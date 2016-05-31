/*
ヒープの作成(下方移動)
*/

#include <stdio.h>

void swap(int *, int *);

int main(void) {
	int heap[100];
	int i, n, p, s, m;

	n = 1;
	while(scanf("%d", &heap[n]) == 1)
		n++;

	m = n - 1;
	for(i = m / 2; i >= 1; i--) {
		p = i;
		s = 2 * p;
		while(s <= m) {
			if(s < m && heap[s + 1] < heap[s])
				s++;
			if(heap[p] <= heap[s])
				break;
			swap(&heap[p], &heap[s]);
			p = s;
			s = 2 * p;
		}
	}

	for(i = 1; i < n; i++)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}

void swap(int *x, int *y) {
	int w;

	w = *x;
	*x = *y;
	*y = w;
}