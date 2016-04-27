/*
ニュートン法
*/

#include <stdio.h>
#include <math.h>

#define f(x) ((x) * (x) * (x) - (x) + 1)
#define g(x) (3 * (x) * (x) - 1)
#define EPS 1e-8  /* 打ち切り誤差 */
#define LIMIT 50  /* 打ち切り回数 */

int main(void) {
	double x = -2.0, dx;
	int k;

	for(k = 1; k <= LIMIT; k++) {
		dx = x;
		x = x - f(x) / g(x);
		if(fabs(x - dx) < fabs(dx) * EPS) {
			printf("x = %f\n", x);
			break;
		}
	}
	if(k > LIMIT)
		printf("収束しない\n");

	return 0;
}