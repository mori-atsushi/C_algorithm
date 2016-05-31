/*
ヒープの作成
*/

#include <stdio.h>

void swap(int *, int *);

int main(void) {
	int heap[100];
	int n, i, s, p, w;

	n = 1;
	while(scanf("%d", &heap[n]) == 1) {
		s = n;
		p = s / 2;
		while(s >= 2 && heap[p] > heap[s]) {
			swap(&heap[p], &heap[s]);
			s = p;
			p = s / 2;
		}
		n++;
	}

	for(i = 1; i < n; i++)
		printf("%d ", heap[i]);
	printf("\n");
}

void swap(int *x, int *y) {
	int w;

	w = *x;
	*x = *y;
	*y = w;
}