#include <iostream>

static unsigned int callCount = 0;

unsigned int factorial(unsigned int);
unsigned int factorial(unsigned int n) {

  ++callCount;

  return (n == 0 ? 1 : n == 1 ? 1 : n + factorial(n - 1));
}

int main() {

  for (unsigned int i = 0; i < 20; ++i) {

    // Clear call count
    callCount = 0;

    // Generate sequence
    factorial(i);

    std::cout << i << ",\t" << callCount << std::endl;
  }

  return 0;
}
