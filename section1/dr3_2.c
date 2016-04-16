/*
順位付け(負のデータ版)
*/

#include <stdio.h>

#define Num 10
#define Max 36
#define Min -20
#define Bias 1 - (Min) /* 最小値を配列要素の１に対応させる */

int main(void) {
	int a[] = {-3, 2, 3, -1, -2, -6, 2, -1, 1, 5};
	int i, juni[Max + Bias + 1];

	for(i = Min + Bias; i <= Max + Bias; i++)
		juni[i] = 0;

	for(i = 0; i < Num; i++)
		juni[a[i] + Bias]++;

	juni[0] = 1;
	for(i = Min + Bias; i <= Max + Bias; i++)
		juni[i] = juni[i] + juni[i - 1];

	printf("  得点  順位\n");
	for(i = 0; i < Num; i++) {
		printf("%6d%6d\n", a[i], juni[a[i] + Bias - 1]);
	}

	return 0;
}