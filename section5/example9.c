/*
自己再編成探索(先頭に移す)
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
	tfield *head, *p, *old;

	head = NULL;
	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		p->pointer = head;
		head = p;
	}

	while(printf("\nKey Name ? "), scanf("%s", key) != EOF) {
		p = old = head;
		while(p != NULL) {
			if(strcmp(key, p->name) == 0) {
				printf("%15s%15s\n", p->name, p->tel);
				if(p != head) {
					old->pointer = p->pointer;
					p->pointer = head;
					head = p;
				}
				break;
			}
			old = p;
			p = p->pointer;
		}
	}

	return 0;
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}