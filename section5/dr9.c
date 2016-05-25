/*
自己再編成探索(１つ前に移す) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp {
	char name[20]; /* 名前 */
	char tel[20]; /* 電話番号 */
	struct temp *pointer; /* 次データへのポインタ */
} tfield;

tfield *talloc(void);

int main(void) {
	char key[20];
	tfield *head, *p, *old1, *old2, *q;

	head = NULL;
	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		p->pointer = head;
		head = p;
	}

	/* ダミー・ノード */
	p = talloc();
	p->pointer = head;
	head = p;

	while(printf("\nKey Name ? "), scanf("%s", key) != EOF) {
		p = head->pointer;
		old1 = old2 = head;
		while(p != NULL) {
			if(strcmp(key, p->name) == 0) {
				printf("%15s%15s\n", p->name, p->tel);
				if(p != head->pointer) {
					q = old1->pointer;
					old1->pointer = p;
					old2->pointer = p->pointer;
					p->pointer = q;
				}
				break;
			}
			old1 = old2;
			old2 = p;
			p = p->pointer;
		}
	}

	return 0;
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}