/*
奇数魔法陣
*/

#include <stdio.h>

#define N 7

int main(void) {
	int hojin[N + 1][N + 1], i, j, k;

	j = (N + 1) / 2;
	i = 0;
	for(k = 1; k <= N * N; k++) {
		if((k % N) == 1) {
			i++;
		} else {
			i--;
			j++;
		}
		if(i == 0)
			i = N;
		if(j > N)
			j = 1;
		hojin[i][j] = k;
	}

	printf("    奇数魔法陣 (N = %d)\n", N);
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++)
			printf("%4d", hojin[i][j]);
		printf("\n");
	}

	return 0;
}