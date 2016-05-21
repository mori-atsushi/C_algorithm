/*
双方向リストデータの作成
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp {
	struct temp *left; /* 逆ポインタ */
	char name[20]; /* 名前 */
	char tel[20]; /* 電話番号 */
	struct temp *right; /* 順ポインタ */
} tfield;

tfield *talloc(void);

int main(void) {
	tfield *head, *tail, *p;

	tail = NULL;
	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		p->left = tail;
		tail = p;
	}

	p = tail;
	head = NULL;
	while(p != NULL) {
		p->right = head;
		head = p;
		p = p->left;
	}

	printf("\n順方向リスト\n");
	p = head;
	while(p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->right;
	}

	printf("\n逆方向リスト\n");
	p = tail;
	while(p != NULL) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;		
	}

 	return 0;
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}