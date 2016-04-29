/*
多桁計算
*/

#include <stdio.h>

#define KETA 20                /* 桁数 */
#define N ((KETA - 1) / 4 + 1) /* 配列サイズ */

void lmul(short *, short, short *);
void ldiv(short *, short, short *);
void print(short *);

int main(void) {
	short a[N + 2] = {   0, 3050, 2508, 8080, 1233},
	      c[N + 2];

	lmul(a, 101, c);
	print(c);
	ldiv(a, 200, c);
	print(c);

	return 0;
}

/* ロング数 * ショート数 */
void lmul(short a[], short b, short c[]) {
	short i;
	long d, cy = 0;

	for(i = N - 1; i >= 0; i--) {
		d = a[i];
		c[i] = (d * b + cy) % 10000;
		cy = (d * b + cy) / 10000;
	}
}

/* ロング数 / ショート数 */
void ldiv(short a[], short b, short c[]) {
	short i;
	long d, rem = 0;

	for(i = 0; i < N; i++) {
		d = a[i];
		c[i] = (short)((d + rem) / b);
		rem = ((d + rem) % b) * 10000;
	}
}

/* ロング数の表示 */
void print(short c[]) {
	short i;
	for(i = 0; i < N; i++)
		printf("%04d ", c[i]);
	printf("\n");
}