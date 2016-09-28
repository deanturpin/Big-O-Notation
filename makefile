all: exponential.o linear.o

%.o:%.cpp
	echo comp $<
	clang++ -Weverything -o $@ -c $<

clean:
	rm -f *.png *.o
