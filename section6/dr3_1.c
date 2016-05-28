/*
2分探索木のサーチ(再帰版)
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
tnode *gentree(tnode * , char *);
tnode *search(tnode *, char *);

int main(void) {
	char key[12];
	tnode *root, *p;

	root = NULL;
	while(scanf("%s", key) != EOF) {
		if(strcmp("q", key) == 0)
			break;
		root = gentree(root, key);
	}

	rewind(stdin);

	while(printf("Search name -->"), scanf("%s", key) != EOF) {
		if((p = search(root, key)) != NULL)
			printf("%sが見つかりました\n", p->name);
		else
			printf("見つかりません\n");
	}

	return 0;
}

/* 木のサーチ */
tnode *search(tnode *p, char *key) {
	if(p == NULL || strcmp(key, p->name) == 0)
		return p;
	else if(strcmp(key, p->name) < 0)
		return search(p->left, key);
	else
		return search(p->right, key);
}

/* 木の作成の再帰手続き */
tnode *gentree(tnode *p, char *w) {
	if(p == NULL) {
		p = talloc();
		strcpy(p->name, w);
		p->left = p->right = NULL;
	} else if(strcmp(w, p->name) < 0) {
		p->left = gentree(p->left, w);
	} else {
		p->right = gentree(p->right, w);
	}

	return p;
}

/* 記憶領域の取得 */
tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}