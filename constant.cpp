#include <iostream>
#include <vector>

static unsigned int callCount = 0;

template <typename Container> size_t elements();
template <typename Container> size_t elements(Container &n) {

  ++callCount;
  return n.size();
}

int main() {

  for (unsigned int i = 0; i < 20; ++i) {

    // Clear call count
    callCount = 0;

    // Generate sequence
    std::vector<double> v(i);
    elements(v);

    std::cout << i << ",\t" << callCount << std::endl;
  }

  return 0;
}
