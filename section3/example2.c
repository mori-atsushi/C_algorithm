/*
基本挿入法
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100 /* データ数 */

int main(void) {
	int a[N], i, j, t;

	for(i = 0; i < N; i++)
		a[i] = rand();

	for(i = 1; i < N; i++) {
		for(j = i - 1; j >= 0; j--) {
			if(a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			} else {
				break;
			}
		}
	}

	for(i = 0; i < N; i++)
		printf("%11d", a[i]);
	printf("\n");

	return 0;
}