/*
2分岐探索木の作成
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	struct temp *left;
	char name[12];
	struct temp *right;
} tnode;

tnode *talloc(void);

int main(void) {
	char dat[12];
	tnode * root, *p, *old;

	root = talloc(); /* ルートノード */
	scanf("%s", root->name);
	root->left = root->right = NULL;

	while(scanf("%s", dat) != EOF) {
		if(strcmp("q", dat) == 0)
			break;
		p = root;
		while(p != NULL) {
			old = p;
			if(strcmp(dat, p->name) <= 0)
				p = p->left;
			else
				p = p->right;
		}
		p = talloc();
		strcpy(p->name, dat);
		strcpy(p->name, dat);
		p->left = p->right = NULL;
		if(strcmp(dat, old->name) <= 0)
			old->left = p;
		else
			old->right = p;
	}

	p = root;
	while(p->left != NULL)
		p = p->left;
	printf("最小ノード = %12s\n", p->name);

	p = root;
	while(p->right != NULL)
		p = p->right;
	printf("最大ノード = %12s\n", p->name);

	return 0;
}

/* 記憶領域の取得 */
tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}