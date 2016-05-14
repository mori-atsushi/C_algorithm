/*
クイック・ソート
*/

#include <stdio.h>

void quick(int *, int, int);

#define N 10
void swap(int *, int *);

int main(void) {
	static int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};
	int k;

	quick(a, 0, N - 1);

	for(k = 0; k < N; k++)
		printf("%4d", a[k]);
	printf("\n");

	return 0;
}

void quick(int a[], int left, int right) {
	int s, t, i, j;

	if(left < right) {
		s = a[(left + right) / 2];
		i = left - 1;
		j = right + 1;
		while(1) {
			while(a[++i] < s);
			while(a[--j] > s);
			if(i >= j)
				break;
			swap(&a[i], &a[j]);
		}

		quick(a, left, i - 1);
		quick(a, j + 1, right);
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}