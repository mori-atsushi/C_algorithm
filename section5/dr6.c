/*
循環・双方向リストデータの作成
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
	tfield *head, *p;

	head = talloc();
	head->left = head->right = head;

	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		p->right = head;
		p->left = head->left;
		head->left->right = p;
		head->left = p;
	}

	printf("\n順方向リスト\n");
	p = head->right;
	while(p != head) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->right;
	}

	printf("\n逆方向リスト\n");
	p = head->left;
	while(p != head) {
		printf("%15s%15s\n", p->name, p->tel);
		p = p->left;		
	}

 	return 0;
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}