/*
グラフの探索(深さ優先探索)
*/

#include <stdio.h>

#define N 8

int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 1, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 1, 0, 0, 0},
                       {0, 0, 0, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 1, 1},
                       {0, 0, 0, 1, 0, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 1, 1, 0}};
int v[N + 1];

void visit(int);

int main(void) {
	int i, k;

	for(k = 1; k <=N; k++) {
		for(i = 1; i <= N; i++)
			v[i] = 0;
		visit(k);
		printf("\n");
	}

	return 0;
}

void visit(int i) {
	int j;

	v[i] = 1;
	for(j = 1; j <= N; j++) {
		if(a[i][j] == 1 && v[j] == 0) {
			printf("%d->%d ", i, j);
			visit(j);
		}
	}
}