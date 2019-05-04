#include <iostream>
#include <vector>
#include <numeric>

static unsigned int callCount = 0;

// Binary search
template <typename Iterator>
bool exists(Iterator begin, Iterator end, const unsigned int n) {

  ++callCount;

  // Find the middle element
  Iterator middle = begin + distance(begin, end) / 2;

  return *middle == n
             ? true
             : begin == (end - 1) ? false
                                  : *middle < n ? exists(middle, end, n)
                                                : exists(begin, middle, n);
}

int main() {

  for (size_t i = 1; i < 100; ++i) {

    // Clear call count
    callCount = 0;

    // Create a container to search
    std::vector<unsigned int> b(i);
    std::iota(b.begin(), b.end(), 0);

    // Search for a value that's out of range (worst case)
    exists(b.cbegin(), b.cend(), i);

    std::cout << i << ",\t" << callCount << '\n';
  }
}
