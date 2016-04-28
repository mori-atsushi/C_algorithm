/*
ラグランジュ補間
*/

#include <stdio.h>

double lagrange(double *, double *, int, double);

int main(void) {
	double x[] = {0.0, 1.0, 3.0, 6.0, 7.0},
	       y[] = {0.8, 3.1, 4.5, 3.9, 2.8};
	double t;

	printf("     x     y\n");
	for(t = 0; t <= 7.0; t = t + .5)
		printf("%7.2f%7.2f\n", t, lagrange(x, y, 5, t));

	return 0;
}

double lagrange(double x[], double y[], int n, double t) {
	int i, j;
	double s, p;

	s = 0.0;
	for(i = 0; i < n; i++) {
		p = y[i];
		for(j = 0; j < n; j++) {
			if(i != j)
				p = p * (t - x[j]) / (x[i] - x[j]);
		}
		s = s + p;
	}
	return s;
}