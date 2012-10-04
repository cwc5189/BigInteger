#include <iostream>
#include "BigInt.h"
#include <time.h>

int main() {
		BigInt test(2);	
		clock_t tStart = clock();
		for(int i = 0; i < 999; i++){
			test = test * 2;
		}
		std::cout << test << std::endl;

		printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

		system("Pause");
		return 0;
}