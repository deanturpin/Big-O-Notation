complexity.o: complexity.cpp
	clang++ -Weverything -o $@ $<

clean:
	rm -f *.o

generate: complexity.o
	# Add header
	cat header.md > readme.md
	# Create image
	./complexity.o | gnuplot -p -e "set datafile separator ','; set output 'image/exponential.png'; set terminal png; plot '-' using 1:2 w l"
	# Add link to image
	echo Exponential >> readme.md
	echo '![](image/exponential.png)' >> readme.md
