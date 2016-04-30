/*
階乗の多桁計算
*/

#include <stdio.h>

void lmul(short *, short, short *);
void printresult(short *);

#define L 64                         /* 求める桁数 */
#define L2 ((L + 3) / 4)             /* 一つ余分に取る */

int main(void) {
	short s[L2];
	short k;
	for(k = 0; k < 2; k++)
		s[k] = 0;

	s[L2 - 1] = 1;
	for(k = 1; k <= 49; k++) {
		lmul(s, k, s);
		printf("%2d != ", k);
		printresult(s);
	}

	return 0;
}

/* 結果の表示 */
void printresult(short c[]) {
	short i;
	for(i = 0; i < L2; i++)
		printf("%04d", c[i]);
	printf("\n");
}

/* ロング数 * ショート数 */
void lmul(short a[], short b, short c[]) {
	short i;
	long d, cy = 0;

	for(i = L2 - 1; i >= 0; i--) {
		d = a[i];
		c[i] = (d * b + cy) % 10000;
		cy = (d * b + cy) / 10000;
	}
}
