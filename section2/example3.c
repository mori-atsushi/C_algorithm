/*
テイラー展開(exp(x))
*/

#include <stdio.h>
#include <math.h>

double myexp(double);

int main(void) {
	double x;
	printf("    x      myexp(x)        exp(x)\n");
	for(x = 0; x < 40; x = x + 10)
		printf("%5.1f%14.6g%14.6g\n", x, myexp(x), exp(x));
}

double myexp(double x) {
	double EPS = 1e-08;
	double s = 1.0, e = 1.0, d;
	int k;

	for(k = 1; k <= 200; k++) {
		d = s;
		e = e * x / k;
		s = s + e;
		if(fabs(s - d) < EPS * fabs(d)) /* 打ち切り誤差 */
			return s;
	}

	return 0.0; /* 収束しない時 */
}