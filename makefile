.SILENT:

complexity.o: complexity.cpp
	clang++ -Weverything -o $@ $<

clean:
	rm -f *.o

generate: complexity.o
	echo 'See ![Installation instructions](install.md).'
	# Create image and add a link to it
	./complexity.o | gnuplot -p -e "set datafile separator ','; set output 'image/exponential.png'; set terminal png; plot '-' using 1:2 w l"
	echo '### Exponential' >> readme.md
	echo '![](image/exponential.png)' >> readme.md
