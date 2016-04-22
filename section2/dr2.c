/*
シンプソンの定積分
*/

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4 - (x) * (x))) /* 被積分関数 */

int main(void) {
	int k;
	double a, b, n, h, fo, fe, sum;

	printf("積分区間 A, B ? :");
	scanf("%lf %lf", &a, &b);

	n = 50;  /* a ~ b間の分割数 */
	h = (b - a) / (2 * n);
	fo = 0;
	fe = 0;

	for(k = 1; k <= 2 * n - 3; k = k + 2) {
		fo = fo + f(a + h * k);
		fe = fe + f(a + h * (k + 1));
	}

	sum = (f(a) + f(b) + 4 * (fo + f(b - h)) + 2 * fe) * h / 3;
	printf("  /%f\n", b);
	printf("  \\  sqrt(4 - x * x) = %f\n", sum);
	printf("  /%f\n", a);

	return 0;
}