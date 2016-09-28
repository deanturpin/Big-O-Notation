#include <iostream>
#include <iomanip>

namespace bigo {

	using namespace std;

	static unsigned int callCount = 0;

	unsigned int factorial(unsigned int n);
	unsigned int factorial(unsigned int n) {

		++callCount;

		return (1 == n ? 1 : n + factorial(n - 1));
	}

	void generateSequence();
	void generateSequence() {
	
		for (unsigned int i = 0; i < 20; ++i) {

			// Clear call count
			callCount = 0;

			// Generate sequence
			factorial(i);

			cout << i << ",\t" << callCount << endl;
		}
	}
}

int main() {

	bigo::generateSequence();
	return 0;
}
