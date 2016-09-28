complexity.o: complexity.cpp
	clang++ -Weverything -o $@ $<

clean:
	rm -f *.o

generate: complexity.o
	cat header.md > readme.md	
	./complexity.o | gnuplot -p -e "set datafile separator ','; set output 'comp.png'; plot '-' using 1:2 w l"
