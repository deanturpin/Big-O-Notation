complexity.o: complexity.cpp
	clang++ -Weverything -o $@ $<

clean:
	rm -f *.o

generate:
	#
