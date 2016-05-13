/*
順列の生成(辞書式順でない)
*/

#include <stdio.h>

#define N 4
int p[N + 1];

void perm(int);
void swap(int *, int *);

int main(void) {
	int i;

	/* 初期設定 */
	for(i = 1; i <= N; i++)
		p[i] = i;
	perm(1);

	return 0;
}

void perm(int i) {
	int j, t;

	if(i < N) {
		for(j = i; j <= N; j++) {
			swap(&p[i], &p[j]);
			perm(i + 1);
			swap(&p[i], &p[j]);
		}
	} else {
		for(j = 1; j <= N; j++)
			printf("%d ", p[j]);
		printf("\n");
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}