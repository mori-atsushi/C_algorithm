/*
フォボナッチ数(非再帰版)
*/

#include <stdio.h>

long fib(long);

int main(void) {
	long n;
	for(n = 1; n <= 20; n++)
		printf("%3ld: %ld\n", n, fib(n));

	return 0;
}

long fib(long n) {
	long a, b, dummy, k;
	a = 1L;
	b = 1L;
	for(k = 3; k <= n; k++) {
		dummy = b;
		b = a + b;
		a = dummy;
	}
	return b;
}