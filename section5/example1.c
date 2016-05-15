/*
スタック
*/

#include <stdio.h>

#define MaxSize 100 /* スタック・サイズ */
int stack[MaxSize];
int sp = 0;
int push(int);
int pop(int *);

int main(void) {
	int c, n;

	while(printf("]"), (c = getchar()) != EOF) {
		rewind(stdin);
		if(c == 'i' || c == 'I') {
			printf("data--> ");
			scanf("%d", &n);
			rewind(stdin);
			if(push(n) == -1)
				printf("スタックがいっぱいです\n");
		}

		if(c == 'o' || c == 'O') {
			if(pop(&n) == -1)
				printf("スタックは空です\n");
			else
				printf("stack data --> %d\n", n);
		}
	}
}

/* スタックにデータを積む手続き */
int push(int n) {
	if(sp < MaxSize) {
		stack[sp] = n;
		sp++;
		return 0;
	} else {
		return -1; /* スタックがいっぱいの時 */
	}
}

/* スタックからデータを取り出す手続き */
int pop(int *n) {
	if(sp > 0) {
		sp--;
		*n = stack[sp];
		return 0;
	} else {
		return -1; /* スタックがからの時 */
	}
}