/*
基本挿入法(番兵を立てる)
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100 /* データ数 */

int main(void) {
	int a[N + 1], i, j, t;

	for(i = 1; i <= N; i++)
		a[i] = rand();

	a[0] = -9999;
	for(i = 2; i <= N; i++) {
		t = a[i];
		for(j = i - 1; a[j] > t; j--)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}

	for(i = 1; i <= N; i++)
		printf("%11d", a[i]);
	printf("\n");

	return 0;
}