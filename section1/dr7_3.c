/*
素因数分解
*/

#include <stdio.h>

int main(void) {
	int a, n;

	while(printf("Number ? : "), scanf("%d", &n) != EOF) {
		a = 2;
		while(n >= a * a) {
			if(n % a == 0) {
				printf("%d * ", a);
				n = n / a;
			}
			else {
				a++;
			}
		}
		printf("%d\n", n);
	}

	return 0;
}