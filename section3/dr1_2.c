/*
シェイカー・ソート
*/

#include <stdio.h>

#define N 9

int main(void) {
	int a[] = {3, 5, 6, 9, 2, 7, 8, 10, 4};
	int left, right, i, shift, t;

	left = 0;
	right = N - 1;

	while(left < right) {
		for(i = left; i < right; i++) {
			if(a[i] > a[i + 1]) {
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				shift = i;
			}
		}

		right = shift;

		for(i = right; i > left; i--) {
			if(a[i] < a[i - 1]) {
				t = a[i];
				a[i] = a[i - 1];
				a[i - 1] = t;
				shift = i;				
			}
		}
		left = shift;
	}

	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}