/*
度数分布（ヒストグラム）
*/

#include <stdio.h>

#define Num 20

int main(void) {
	int a[] = {35, 25, 56, 78, 43, 66, 71, 73, 80, 90,
	           0, 73, 35, 65, 100, 78, 80, 85, 35, 50};
	int i, rank, histo[11];

	for(i = 0; i <= 10; i++)
		histo[i] = 0;

	for(i = 0; i < Num; i++) {
		rank = a[i] / 10;
		if(0 <= rank && rank <= 10)
			histo[rank]++;
	}

	for(i = 0; i <= 10; i++)
		printf("%3d -  :%3d\n", i * 10, histo[i]);

	return 0;
 }