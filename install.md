https://en.wikipedia.org/wiki/Big_O_notation

### Dependencies
```
clang
gnuplot
```

### Compile code, generate images and documentation
See [readme.md](readme.md).
```bash
make
```

### Remove all objects and images
```bash
make clean
```

### Adding new complexities
- Create new source file ```new.cpp```
- Add new target to top of makefile ```new.png```

Output should be iteration and a measure of complexity. In this case it is the
number of calls of a Fibonacci sequence calculator.

```bash
$ exponential/foo
0,      0
1,      1
2,      1
3,      2
4,      3
5,      5
6,      8
7,      13
8,      21
9,      34
10,     55
11,     89
12,     144
13,     233
14,     377
15,     610
16,     987
17,     1597
18,     2584
19,     4181

```
