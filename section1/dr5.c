/*
モンテカルロ法による免責の計算
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

double rnd(void);

int main(void) {
	double x, y, s;
	int i, in = 0;

	for(i = 0; i < NUM; i++) {
		x = 2 * rnd();
		y = rnd();
		if(x * x / 4 + y * y <= 1)
			in++;
	}

	s = 4.0 * (2.0 * in / NUM);
	printf("楕円の面積=%f\n", s);

	return 0;
}

/* 0 ~ 1の乱数 */
double rnd(void) {
	return (double)rand() / (RAND_MAX + 0.1);
}