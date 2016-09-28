# Ultimately we want to end up with some images
all: exponential.png linear.png

# Define how to create an object from a source file
%.o:%.cpp
	echo comp $<
	clang++ -Weverything -o $@ $<

# And how to create an image from an object
%.png:%.o
	./$< | gnuplot -p -e "set datafile separator ','; set output '"$@"'; set terminal png; plot '-' using 1:2 w l"

clean:
	rm -f *.png *.o
