/*
リストデータの制作
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	char name[20]; /* 名前 */
	char tel[20]; /* 電話番号 */
	struct temp *pointer; /* 次データへのポインタ */
} tfield;

tfield *talloc(void);

int main(void) {
	tfield *head, *p, *old;
	head = talloc();
	old = head;

	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		old->pointer = p;
		old = p;
	}

	p = head->pointer;
	while(p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}