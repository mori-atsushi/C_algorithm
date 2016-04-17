/*
ランダムな順列(改良版)
*/

#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);
void swap(int *, int *);

int main(void) {
	int i, j, d, a[N + 1];

	for(i = 1; i <= N; i++)
		a[i] = i;

	for(i = N; i > 1; i--) {
		j = irnd(i - 1);
		swap(&a[i], &a[j]);
	}

	for(i = 1; i <= N; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

/* 1 〜 nの乱数 */
int irnd(int n) {
	return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}

/* a と bを入れ替える */
void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

	return ;
}