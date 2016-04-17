/*
ランダムな順列
*/

#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

int main(void) {
	int i, j, flag, a[N + 1];

	a[1] = irnd(N);
	for(i = 2; i <= N; i++) {
		do {
			a[i] = irnd(N);
			flag = 0;
			for(j = 1; j < i; j++) {
				if(a[i] == a[j]) {
					flag = 1;
					break;
				}
			}
		} while(flag == 1);
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