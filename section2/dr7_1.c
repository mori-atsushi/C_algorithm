/*
eの多桁計算
*/

#include <stdio.h>

void ladd(short *, short *, short *);
void lsub(short *, short *, short *);
void ldiv(short *, short, short *);
void printresult(short *);

#define L 1000                         /* 求める桁数 */
#define L1 ((L / 4) + 1)               /* 配列のサイズ */
#define L2 (L1 + 1)                    /* 一つ余分に取る */
#define N 451     /* 計算する項数 */

int main(void) {
	short s[L2 + 2], w[L2 + 2];
	short k;

	for(k = 0; k <= L2; k++)
		s[k] = w[k] = 0;

	s[0] = w[0] = 1;
	for(k = 1; k <= L2; k++) {
		ldiv(w, k, w);
		ladd(s, w, s);
	}
	printresult(s);

	return 0;
}

/* 結果の表示 */
void printresult(short c[]) {
	short i;
	printf("%3d. ", c[0]);   /* 最上位桁の表示 */
	for(i = 1; i < L1; i++)
		printf("%04d ", c[i]);
	printf("\n");
}

/* ロング数 + ロング数 */
void ladd(short a[], short b[], short c[]) {
	short i, cy = 0;
	for(i = L2; i >= 0; i--) {
		c[i] = a[i] + b[i] + cy;
		if(c[i] < 10000) {
			cy = 0;
		} else {
			c[i] = c[i] - 10000;
			cy = 1;
		}
	}
}

/* ロング数 - ロング数 */
void lsub(short a[], short b[], short c[]) {
	short i, brrw = 0;
	for(i = L2; i >= 0; i--) {
		c[i] = a[i] - b[i] - brrw;
		if(c[i] >= 0) {
			brrw = 0;
		} else {
			c[i] = c[i] + 10000;
			brrw = 1;
		}
	}
}

/* ロング数 / ショート数 */
void ldiv(short a[], short b, short c[]) {
	short i;
	long d, rem = 0;

	for(i = 0; i < L2; i++) {
		d = a[i];
		c[i] = (short)((d + rem) / b);
		rem = ((d + rem) % b) * 10000;
	}
}