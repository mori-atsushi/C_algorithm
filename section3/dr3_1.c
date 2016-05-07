/*
逐次処理法(番兵を立てる)
*/

#include <stdio.h>
#include <string.h>

#define N 10 /* データ数 */

typedef struct {
	char name[20];
	int age;
} girl;

int main(void) {
	girl a[N + 1] = {"Ann", 18, "Rolla", 19, "Nancy", 16, "Eluza", 17, "Juliet", 18, "Machilda", 20, "Emy", 15, "Candy", 16, "Ema", 17, "Mari", 18};
	char key[20];
	int i;


	printf("検索するdata?：");
	scanf("%s", key);

	strcpy(a[N].name, key); /* 番兵 */
	i = 0;
	while(strcmp(key, a[i].name) != 0)
		i++;

	if(i < N)
		printf("%s %d\n", a[i].name, a[i].age);
	else
		printf("見つかりませんでした\n");
		
	return 0;
}