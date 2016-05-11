/*
nCrの計算(再帰版)
*/

#include <stdio.h>

long combi(int, int);

int main(void) {
	int n, r;

	for(n = 0; n <= 5; n++) {
		for(r = 0; r <= n; r++)
			printf("%d C %d = %2ld  ", n, r, combi(n, r));
		printf("\n");
	}
	return 0;
}

long combi(int n, int r) {
	if(r == 0 || r == n)
		return 1L;
	else
		return combi(n - 1, r) + combi(n - 1, r - 1);
}