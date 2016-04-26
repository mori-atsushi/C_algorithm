/*
テイラー展開
*/

#include <stdio.h>
#include <math.h>

double mycos(double);

int main(void) {
	double x, rd = 3.14159 / 180;
	printf("    x      mycos(x)        cos(x)\n");
	for(x = 0; x <= 180; x = x + 10)
		printf("%5.1f%14.6f%14.6f\n", x, mycos(x * rd), cos(x * rd));

	return 0;
}

double mycos(double x) {
	double EPS = 1e-08;
	double s = 1.0, e = 1.0, d;
	int k;

	x = fmod(x, 2*3.14159265358979); /* xの値を0 ~ 2πに収める */
	for(k = 1; k <= 200; k = k + 2) {
		d = s;
		e = - e * x * x / (k * (k + 1));
		s = s + e;
		if(fabs(s -d) < EPS * fabs(d)) /* 打ち切り誤差 */
			return s;
	}
	return 9999.0; /* 収束しない時 */
}