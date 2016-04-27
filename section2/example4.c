/*
2分法
*/

#include <stdio.h>
#include <math.h>

#define f(x) ((x) * (x) * (x) - (x) + 1)
#define EPS 1e-08  /* 打ち切り誤差 */
#define LIMIT 50   /* 打ち切り回数 */

int main(void) {
	double low, high, x;
	int k;

	low = -2.0;
	high = 2.0;
	for(k = 0; k <= LIMIT; k++) {
		x = (low + high) / 2;
		if(f(x) > 0)
			high = x;
		else
			low = x;
		if(f(x) == 0 || fabs(high - low) < fabs(low) * EPS) {
			printf("x = %f\n", x);
			break;
		}
	}
	if(k > LIMIT)
		printf("収束しない\n");

	return 0;
}