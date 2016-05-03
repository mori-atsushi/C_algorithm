/*
線形計画法(Linea Programing)
*/

#include <stdio.h>
#include <math.h>

#define N1 4 /* 行数 */
#define N2 6 /* 列数 */
#define N3 2 /* 変数の数 */

int main(void) {
	double a[N1][N2] = {{ 1.0,  2.0,  1.0,  0.0,  0.0,  14.0},
	                    { 1.0,  1.0,  0.0,  1.0,  0.0,  8.0 },
	                    { 3.0,  1.0,  0.0,  0.0,  1.0,  18.0},
	                    {-2.0, -3.0,  0.0,  0.0,  0.0,  0.0 }};
	double min, p, d;
	int j, k, x, y, flag;

	while(1) {
		min = 9999;
		/* 列選択 */
		for(k = 0; k < N2 - 1; k++) {
			if(a[N1 - 1][k] < min) {
				min = a[N1 - 1][k];
				y = k;
			}
		}

		if(min >= 0)
			break;

		min = 9999;
		/* 行選択 */
		for(k = 0; k < N1 - 1; k++) {
			p = a[k][N2 - 1] / a[k][y];
			if(a[k][y] > 0 && p < min) {
				min = p;
				x = k;
			}
		}

		p = a[x][y];  /* ピボット係数 */
		for(k = 0; k < N2; k++)
			a[x][k] = a[x][k] / p; /* ピボット行をpで割る */
		for(k = 0; k < N1; k++) {
			if(k != x) {
				d = a[k][y];
				for(j = 0; j < N2; j++)
					a[k][j] = a[k][j] - d * a[x][j]; /* ピポット行の掃き出し */
			}
		}
	}

	for(k = 0; k < N3; k++) {
		flag = -1;
		for(j = 0; j < N1; j++) {
			if(a[j][k] == 1)
				flag = j;
		}
		if(flag != -1)
			printf("x%d = %f\n", k, a[flag][N2 - 1]);
		else
			printf("x%d = %f\n", k, 0.0);
	}
	printf("z  = %f\n", a[N1 - 1][N2 - 1]);

	return 0;
}