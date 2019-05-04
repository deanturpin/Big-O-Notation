CXX = g++-8
CCFLAGS = --std=c++2a --all-warnings --extra-warnings --pedantic-errors \
	 -Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor -O1

# Ultimately we want to end up with some images
all: readme.md constant.png logarithmic.png linear.png quadratic.png exponential.png

# Initialise the readme if not present
readme.md:
	echo '## Big O Notation' > readme.md
	echo 'See [how this documentation is generated](install.md).' >> readme.md

# Define how to create an object from a source file
%.o: %.cpp
	$(CXX) -o $@ $< $(CCFLAGS)

# And how to create an image from an object
%.png: %.o
	./$< | gnuplot -e "set datafile separator ','; set output '"$@"'; set terminal png; plot '-' using 1:2 w l"
	echo "### $(basename $@)" >> readme.md
	cat $(basename $@).md >> readme.md
	echo >> readme.md
	echo "![]($@)" >> readme.md

# Remove all objects, images and generated readme
clean:
	rm -f *.png *.o readme.md

rebuild: clean all
