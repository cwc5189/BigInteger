#include <iostream>
#include "BigInt.h"
#include <time.h>

int main() {
		BigInt test("2");	
		clock_t tStart = clock();
		test = test ^ 18000;
		std::cout << test << std::endl;

		printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

		
		int temp = 0;
		for(int i = 0; i < test.length(); i++){
			temp += test.at(i);
		}
		std::cout << temp << std::endl;

		system("Pause");
		return 0;
}