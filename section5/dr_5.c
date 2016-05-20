/*
リストデータの削除
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
void del(char *);

int main(void) {
	char key[20];

	genlist();
	displist();

	while(printf("Key Name : "), scanf("%s", key) != EOF) {
		del(key);
		displist();
	}
}

/* リストへの追加 */
void del(char *key) {
	tfield *p;

	p = head;
	while(p->pointer != NULL) {
		if(strcmp(key, p->pointer->name) == 0) {
			p->pointer = p->pointer->pointer;
			return ;
		}
		p = p->pointer;
	}	
	printf("キーデータが見つかりません\n");
}

/* リストの作成 */
void genlist(void) {
	tfield *p;

	head = NULL;
	do {
		p = talloc();
		p->pointer = head;
		head = p;
		scanf("%s %s", p->name, p->tel);
	} while(strcmp(p->name, "q"));
}

/* リストの表示 */
void displist(void) {
	tfield *p;
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