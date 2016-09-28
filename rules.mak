CC=clang++
RM=rm -f

%.o:%.cpp
	echo comp $<
	$(CC) $(FLAGS) -o $@ -c $<

# Compile and link all source files into a single executable
objects := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
foo: $(objects)
	$(CC) -Weverything -o $@ $(objects)

generate:
	# Create image and add a link to it
	./foo | gnuplot -p -e "set datafile separator ','; set output '../image/exponential.png'; set terminal png; plot '-' using 1:2 w l"
	echo '### Exponential' >> ../readme.md
	echo '![](image/exponential.png)' >> ../readme.md

clean:
	$(RM) foo $(objects)
