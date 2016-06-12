/*
ダイナミック・プログラミング（釣り銭の枚数を最小にする）
*/

#include <stdio.h>

#define limit 42
#define n 3

int main(void) {
	int size[] = {1, 10, 25};
	int value[limit + 1], item[limit + 1], i, s, p, newvalue;

	for(s = 0; s <= limit; s++)
		value[s] = s;

	for(i = 0; i < n; i++) {
		for(s = size[i]; s <= limit; s++) {
			p = s - size[i];
			newvalue = value[p] + 1;
			if(newvalue < value[s]) {
				value[s] = newvalue;
				item[s] = i;
			}
		}
	}

	printf("コインの枚数 = %3d : ", value[limit]);
	for(s = limit; s > 0; s = s - size[item[s]])
		printf("%3d, ", size[item[s]]);
	printf("\n");

	return 0;
}