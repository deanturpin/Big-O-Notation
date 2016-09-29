#include <iostream>
#include <vector>

static unsigned int callCount = 0;

template <typename Iterator>
	bool exists(Iterator begin, Iterator end, const unsigned int n) {

		++callCount;

		// std::cout << std::distance(begin, end) << std::endl;
		for (auto i = begin; i != end; ++i)
			std::cout << *i << std::endl;

		/*

		// Find the middle value
		const auto middle = b.length() / 2;

		if (b.at(middle) == n)
			return true;

		if (b.at(middle) < n) {

			// Construct a new string
			const vector<unsigned int> c(b ;
			for (unsigned int i = 0; i < 
			return exists(b, n);
		}
		*/

		return true;
	}

int main() {

	for (unsigned int i = 10; i < 12; ++i) {

		// Clear call count
		callCount = 0;

		// Create a container to search
		std::vector<unsigned int> b;
		std::cout << "# length " << i << std::endl;
		for (unsigned int j = 0; j < i; ++j)
			b.push_back(j);

		// Search for a value that's out of range (worst case)
		exists(b.cbegin(), b.cend(), i);

		// std::cout << i << ",\t" << callCount << std::endl;
	}

	return 0;
}
