/*
台形則による定積分
*/

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4 - (x) * (x))) /* 被積分関数 */

int main(void) {
	int k;
	double a, b, n, h, x, s, sum;

	printf("積分区間A, B ? : ");
	scanf("%lf %lf", &a, &b);

	n = 50;
	h = (b - a) / n;
	x = a;
	s = 0;

	for(k = 1; k < n; k++) {
		x = x + h;
		s = s + f(x);
	}

	sum = h * ((f(a) + f(b)) / 2 + s);
	printf("  /%f\n", b);
	printf("  \\  sqrt(4 - x * x) = %f\n", sum);
	printf("  /%f\n", a);

	return 0;
}