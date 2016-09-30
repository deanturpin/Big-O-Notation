#include <iostream>
#include <vector>

static unsigned int callCount = 0;

template <typename Iterator>
bool exists(Iterator begin, Iterator end, const unsigned int n) {

	++callCount;

	// Find the middle element
	Iterator middle = begin + distance(begin, end) / 2;

	return (

		// We have found it, we are done
		*middle == n ? true :

		// There's only one element left (and we haven't found it)
		begin == (end - 1) ? false :

		// Discard the bottom half
		*middle < n ? exists(middle, end, n) :

		// Discard the top half
		exists(begin, middle, n)
	);

	return false;
}

int main() {

	for (unsigned int i = 1; i < 100; ++i) {

		// Clear call count
		callCount = 0;

		// Create a container to search
		std::vector<unsigned int> b;
		for (unsigned int j = 0; j < i; ++j)
			b.emplace_back(j);

		// Search for a value that's out of range (worst case)
		exists(b.cbegin(), b.cend(), i);

		std::cout << i << ",\t" << callCount << std::endl;
	}

	return 0;
}
