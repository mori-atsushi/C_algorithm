/*
2分探索法
*/

#include <stdio.h>

#define N 10 /* データ数 */

int main(void) {
	int a[] = {2, 3, 7, 11, 31, 50, 55, 70, 77, 80};
	int key, low, high, mid, flag = 0;

	printf("検索するdata?：");
	scanf("%d", &key);

	low = 0;
	high = N - 1;
	while(low <= high) {
		mid = (low * high) / 2;
		if(a[mid] == key) {
			printf("%dは%d番目にありました\n", a[mid], mid + 1);
			flag = 1;
			break;
		}
		if(a[mid] < key)
			low = mid + 1;
		else
			 high = mid - 1;
	}
	if(flag != 1)
		printf("見つかりませんでした\n");

	return 0;
}