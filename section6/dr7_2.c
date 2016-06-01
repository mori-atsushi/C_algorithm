/*
ヒープ・ソート
*/

#include <stdio.h>

void swap(int *, int *);
void shiftdown(int, int, int *);

int main(void) {
	int heap[100];
	int i, n, p, s, m;

	n = 1;
	while(scanf("%d", &heap[n]) == 1)
		n++;

	m = n - 1;
	for(i = m / 2; i >= 1; i--)
		shiftdown(i, m, heap);

	while(m > 1) {
		swap(&heap[1], &heap[m]);
		m--;
		shiftdown(1, m, heap);
	}

	for(i = 1; i < n; i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}

/* 下方移動 */
void shiftdown(int p, int n, int heap[]) {
	int s;
	s = 2 * p;
	while(s <= n) {
		if(s < n && heap[s + 1] > heap[s])
			s++;
		if(heap[p] >= heap[s])
			break;
		swap(&heap[p], &heap[s]);
		p = s;
		s = 2 * p;
	}
}


void swap(int *x, int *y) {
	int w;

	w = *x;
	*x = *y;
	*y = w;
}