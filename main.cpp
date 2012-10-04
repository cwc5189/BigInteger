#include <iostream>
#include "BigInt.h"

int main() {
		BigInt test(50);
		test = test * BigInt(3);
		std::cout << test << std::endl;
		system("Pause");
		return 0;
}