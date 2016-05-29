/*
2分探索木のトラバサール
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
void treewalk(tnode *);

int main(void) {
	char dat[12];
	tnode *root;

	root = NULL;
	while(scanf("%s", dat) != EOF) {
		if(strcmp("q", dat) == 0)
			break;
		root = gentree(root, dat);
	}
	treewalk(root);

	return 0;
}

/* 木のトラバサール */
void treewalk(tnode *p) {
	if(p != NULL) {
		treewalk(p->right);
		printf("%s\n", p->name);
		treewalk(p->left);
	}
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