#include <iostream>
#include "BigInt.h"
#include <time.h>

int main() {
		BigInt test(2);
		clock_t tStart = clock();
		test = test ^ 1000;
		std::cout << test << std::endl;

		printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

		std::string t = "10715086071862673209484250490600018105614048117055336074437503883703510511249361"
"22493198378815695858127594672917553146825187145285692314043598457757469857480393"
"45677748242309854210746050623711418779541821530464749835819412673987675591655439"
"46077062914571196477686542167660429831652624386837205668069376";
		
		int temp = 0;
		for(int i = 0; i < t.length(); i++){
			temp += t.at(i) - '0';
		}

		std::cout << temp << std::endl;

		system("Pause");
		return 0;
}