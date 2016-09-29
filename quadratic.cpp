#include <algorithm>
#include <iostream>
#include <vector>

static unsigned int callCount = 0;

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end) {

	using namespace std;

	for (auto i = begin; i != end - 1; ++i) {

		++callCount;

		auto now = i;
		auto next = (now + 1);

		if (*now > *next) {

			// Swap element
			auto t = *now;
			*now = *next;
			*next = t;

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

		// Make a copy of B
		std::vector<unsigned int> c(sortMe);

		// Search for a value that's out of range (worst case)
		insertionSort(sortMe.begin(), sortMe.end());

		for (const auto &x : c)
			std::cout << x << " ";
		std::cout << std::endl;

		for (const auto &x : sortMe)
			std::cout << x << " ";
		std::cout << std::endl;

		std::cout << "\n" << i << ",\t" << callCount << "\n" << std::endl;
	}

	return 0;
}
