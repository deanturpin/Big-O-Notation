#include <iostream>
#include <vector>

static unsigned int callCount = 0;

template <typename Iterator>
bool exists(Iterator begin, Iterator end, const unsigned int n) {

	using namespace std;

	++callCount;

	// Find the middle element
	Iterator middle = begin + distance(begin, end) / 2;

	// Have I found what I'm looking for?
	if (*middle == n)
		return true;

	if (begin == (end - 1))
		return false;

	if (*middle < n)
		return exists(middle, end, n);
	else
		return exists(begin, middle, n);

	return false;
}

int main() {

	for (unsigned int i = 1; i < 100; ++i) {

		// Clear call count
		callCount = 0;

		// Create a container to search
		std::vector<unsigned int> b;
		for (unsigned int j = 0; j < i; ++j)
			b.push_back(j);

		// Search for a value that's out of range (worst case)
		exists(b.begin(), b.end(), i);

		std::cout << i << ",\t" << callCount << std::endl;
	}

	return 0;
}
