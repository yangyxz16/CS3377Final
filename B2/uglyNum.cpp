#include <stdio.h>
#include <stdlib.h>

int main(void){
	for (int i = 1; i <= 10000; i++) {
		if (i == 1 || i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
			printf("%d, ", i);
		}
	}


	return 0;
}
