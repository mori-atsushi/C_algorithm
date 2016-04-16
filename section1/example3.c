/*
順位付け
*/

#include <stdio.h>

#define Num 10

int main(void) {
	int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
	int juni[Num];
	int i, j;

	for(i = 0; i < Num; i++) {
		juni[i] = 1;
		for(j = 0; j < Num; j++) {
			if(a[j] > a[i])
				juni[i]++;
		}
	}

	printf("  得点  順位\n");
	for(i = 0; i < Num; i++) {
		printf("%6d%6d\n", a[i], juni[i]);
	}

	return 0;
};