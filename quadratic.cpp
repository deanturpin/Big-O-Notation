#include <algorithm>
#include <iostream>
#include <vector>

static unsigned int callCount = 0;

template <typename Iterator> void insertionSort(Iterator begin, Iterator end) {

  for (auto i = begin; i != end - 1; ++i) {

    ++callCount;

    auto now = i;
    auto next = (now + 1);

    if (*now > *next) {

      // Swap element
    std::swap(*now, *next);

      // Return to start
      i = begin;
    }
  }
}

int main() {

  for (unsigned int i = 1; i < 20; ++i) {

    // Clear call count
    callCount = 0;

    // Create something to sort
    std::vector<unsigned int> sortMe;
    for (unsigned int j = 0; j < i; ++j)
      sortMe.emplace_back(j);

    // Reverse it so there's lots to sort
    std::reverse(sortMe.begin(), sortMe.end());

    // Search for a value that's out of range (worst case)
    insertionSort(sortMe.begin(), sortMe.end());

    std::cout << i << ",\t" << callCount << '\n';
  }
}
