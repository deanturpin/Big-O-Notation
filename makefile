complexity.o: complexity.cpp
	clang++ -Weverything -std=c++1y -o $@ $<

clean:
	rm -f *.o
