/*
シェル・ソート(改良挿入法)
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void) {
	int a[N], i, j, k, gap, t;

	for(i = 0; i < N; i++)
		a[i] = rand();

	for(gap = 1; gap < N / 3; gap = 3 * gap + 1)
		;

	while(gap > 0) {
		for(k = 0; k < gap; k++) {
			for(i = k + gap; i < N; i = i + gap) {
				for(j = i - gap; j >= k; j = j - gap) {
					if(a[j] > a[j + gap]) {
						t = a[j];
						a[j] = a[j + gap];
						a[j + gap] = t;
					} else {
						break;
					}
				}
			}
		}
		gap = gap / 3;
	}

	for(i = 0; i < N; i++)
		printf("%11d", a[i]);
	printf("\n");

	return 0;
}