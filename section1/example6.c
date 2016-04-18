/*
ユークリッドの互除法
*/

#include <stdio.h>

int main(void) {
	int a, b, m, n;

	printf("二つの整数を入力してください：");
	scanf("%d %d", &a, &b);

	m = a; n = b;
	while(m != n) {
		if(m > n)
			m = m - n;
		else
			n = n - m;
	}
	printf("最大公約数=%d\n", m);

	return 0;
}