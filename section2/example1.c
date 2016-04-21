/*
一様乱数（線形合同法）
*/

#include <stdio.h>

unsigned rndnum = 13; /* 乱数の初期化 */
unsigned irnd(void);

int main(void) {
	int j;

	for(j = 0; j < 100; j++) {
		printf("%8d", irnd());
	}
	printf("\n");

	return 0;
}

/* 0 ~ 132767の整数乱数 */
unsigned irnd(void) {
	rndnum = (rndnum * 109 + 1021) % 32768;
	return rndnum;
}