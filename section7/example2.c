/*
グラフの探索(幅優先)
*/

#include <stdio.h>

#define N 8

int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 1, 1, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 1, 1},
                       {0, 0, 0, 1, 0, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 1, 1, 0}};
int v[N + 1];

int queue[100];
int head = 0, tail = 0;

int main(void) {
	int i, j;

	for(i = 1; i <= N; i++)
		v[i] = 0;

	queue[tail++] = 1;
	v[1] = 1;
	do{
		i = queue[head++];
		for(j = 1; j <= N; j++) {
			if(a[i][j] == 1 && v[j] == 0) {
				printf("%d->%d ", i, j);
				queue[tail++] = j;
				v[j] = 1;
			}
		}
	} while (head != tail);

	printf("\n");

	return 0;
}