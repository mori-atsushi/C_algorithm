/*
バブル・ソート
*/

#include <stdio.h>

#define N 6

int main(void) {
	int a[] = {80, 41, 35, 90, 40, 20};
	int t, i, j;

	for(i = 0; i < N - 1; i++) {
		for(j = N - 1; j > i; j--) {
			if(a[j] < a[j - 1]) {
				t = a[j];
				a[j] = a[j - 1];
				a[j - 1] = t;
			}
		}
	}

	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	return 0;
}