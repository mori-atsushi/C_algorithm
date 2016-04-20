/*
エラトステネスのふるい
*/

#include <stdio.h>
#include <math.h>

#define NUM 1000

int main(void) {
	int prime[NUM + 1];
	int i, j, Limit;

	for(i = 2; i <= NUM; i++)
		prime[i] = 1;

	Limit = (int)sqrt((double)NUM);

	for(i = 2; i <= Limit; i++) {
		if(prime[i] == 1) {
			for(j = 2 * i; j <= NUM; j++) {
				if(j % i == 0)
					prime[j] = 0;
			}
		}
	}

	printf("\n求められた素数\n");
	for(i = 2; i <= NUM; i++) {
		if(prime[i] == 1)
			printf("%5d", i);
	}
	printf("\n");

	return 0;
}