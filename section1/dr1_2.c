/*
Pascalの３角形
*/

#include <stdio.h>
#define N 12

long combi(int, int);

int main(void) {
	int n, r, t;
	for(n = 0; n <= N; n++) {
		for(t = 0; t < (N - n) * 3; t++) /* 空白 */
			printf(" ");
		for(r = 0; r <= n; r++)
			printf("%3ld   ", combi(n, r));
		printf("\n");
	}

	return 0;
}

long combi(int n, int r) {
	int i;
	long p = 1;

	for (i = 1; i <= r; i++)
		p = p * (n - i + 1) / i;
	return p;
}