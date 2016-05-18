/*
リストデータの探索
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
void genlist(void);
void displist(void);
void link(char *);

int main(void) {
	tfield *head, *p, sentinel;
	char key[20];

	head = &sentinel;
	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		p->pointer = head;
		head = p;
	}

	rewind(stdin);

	while(printf("Key Name : "), scanf("%s", key) != EOF) {
		strcpy(sentinel.name, key);
		p = head;
		while(strcmp(p->name, key) != 0)
			p = p->pointer;
		if(p != &sentinel)
			printf("%s %s\n", p->name, p->tel);
		else
			printf("見つかりません\n");
	}

	return 0;
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}