#include <iostream>
#include <iomanip>

namespace bigo {

	using namespace std;

	static unsigned int callCount = 0;

	unsigned int fibonacci(const unsigned int);
	unsigned int fibonacci(const unsigned int n) {

		using namespace std;
		++callCount;

		return (	
				n == 0 ? 0 :
				n == 1 ? 1 :
				n == 2 ? 1 :
				fibonacci(n - 1) + fibonacci(n - 2)
			   );
	}

	void generateSequence();
	void generateSequence() {
	
		for (unsigned int i = 0; i < 40; ++i)
			cout << i << ",";

		cout << endl;

		for (unsigned int i = 0; i < 40; ++i)
			cout << fibonacci(i) << ",";

		cout << endl;
	}
}

int main() {

	bigo::generateSequence();
	return 0;
}
