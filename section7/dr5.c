/*
最短ルートの表示
*/

#include <stdio.h>
#include <stdlib.h>

#define N 8
#define M 9999

int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 7, 2, M, M, M, M},
                       {0, 1, 0, M, M, 2, 4, M, M},
                       {0, 7, M, 0, M, M, 2, 3, M},
                       {0, 2, M, M, 0, M, M, 5, M},
                       {0, M, 2, M, M, 0, 1, M, M},
                       {0, M, 4, 2, M, 1, 0, M, 6},
                       {0, M, M, 3, 5, M, M, 0, 2},
                       {0, M, M, M, M, M, 6, 2, 0}};

int main(void) {
	int j, k, p, start, min, leng[N + 1], v[N + 1], index[N + 1];

	printf("始点 ");
	scanf("%d", &start);
	for(k = 1; k <= N; k++) {
		leng[k] = M;
		v[k] = 0;
	}
	
	leng[start] = 0;
	index[start] = 0;

	for(j = 1; j <= N; j++) {
		min = M;
		for(k = 1; k <= N; k++) {
			if(v[k] == 0 && leng[k] < min) {
				p = k;
				min = leng[k];
			}
		}
		v[p] = 1;

		if(min == M) {
			printf("グラフは連結でない\n");
			exit(1);
		}

		/* pを経由してkに至る長さがそれまでの最短路より小さければ更新 */
		for(k = 1; k <= N; k++) {
			if((leng[p] + a[p][k]) < leng[k]) {
				leng[k] = leng[p] + a[p][k];
				index[k] = p;
			}
		}
	}

	for(j = 1; j <= N; j++) {
		printf("%3d : %d", leng[j], j);
		p = j;
		while(index[p] != 0) {
			printf(" <-- %d", index[p]);
			p = index[p];
		}
		printf("\n");
	}
}