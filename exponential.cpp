#include <iostream>

static unsigned int callCount = 0;

unsigned int fibonacci(const unsigned int n) {

  ++callCount;

  return (n == 0
              ? 0
              : n == 1 ? 1 : n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2));
}

int main() {

  for (size_t i = 0; i < 20; ++i) {

    // Clear call count
    callCount = 0;

    // Generate sequence
    fibonacci(i);

    std::cout << i << ",\t" << callCount << "\n";
  }
}
