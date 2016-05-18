/*
リストデータへの追加
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	char name[20]; /* 名前 */
	char tel[20]; /* 電話番号 */
	struct temp *pointer; /* 次データへのポインタ */
} tfield;

tfield *head;
tfield *talloc(void);
void genlist(void);
void displist(void);
void link(char *);

int main(void) {
	char key[20];

	genlist();
	displist();

	while(printf("Key Name : "), scanf("%s", key) != EOF) {
		link(key);
		displist();
	}
}

/* リストへの追加 */
void link(char *key) {
	tfield *p, *n;

	n = talloc();
	printf("追加データ : ");
	scanf("%s %s", n->name, n->tel);
	p = head;
	while(p != NULL) {
		if(strcmp(key, p->name) == 0) {
			n->pointer = p->pointer;
			p->pointer = n;
			return ;
		}
		p = p->pointer;
	}	
	printf("%s が見つからないので先頭に追加します。\n", key);
	n->pointer = head;
	head = n;
}

/* リストの作成 */
void genlist(void) {
	tfield *p;

	head = NULL;
	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		p->pointer = head;
		head = p;
	}
}

/* リストの表示 */
void displist(void) {
	tfield *p;
	p = head;

	while(p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}