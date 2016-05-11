/*
階乗計算の再帰解
*/

#include <stdio.h>

long kaijo(int);

int main(void) {
	int n;
	for(n = 0; n < 13; n++)
		printf("%2d! = %10ld\n", n, kaijo(n));

	return 0;
}

/* 再帰手続 */
long kaijo(int n) {
	if(n == 0)
		return 1L;
	else
		return n * kaijo(n - 1);
}