/*
連立方程式の解法(ガウスの消去法)
*/

#include <stdio.h>

#define N 3 /* 元の数 */

int main(void) {
	double a[N][N + 1] = {{2.0  ,3.0  ,1.0  ,4.0  },
                          {4.0  ,1.0  ,-3.0 ,-2.0 },
                          {-1.0 ,2.0  ,2.0  ,2.0  }};
	double d;
	int i, j, k;

	/* 前進消去 */
	for(k = 0; k < N - 1; k++) {
		for(i = k + 1; i < N; i++) {
			d = a[i][k] / a[k][k];
			for(j = k + 1; j <= N;j++)
				a[i][j] = a[i][j] - a[k][j] * d;
		}
	}

	/* 後退代入*/
	for(i = N - 1; i >= 0; i--) {
		d = a[i][N];
		for(j = i + 1; j < N; j++)
			d = d - a[i][j] * a[j][N];
		a[i][N] = d / a[i][i];
	}

	for(k = 0; k < N; k++)
		printf("x%d=%f\n", k + 1, a[k][N]);

	return 0;
}