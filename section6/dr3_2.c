/*
2分探索木の作成(再帰版)
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
void gentree(tnode ** , char *);

int main(void) {
	char dat[12];
	tnode *root;

	root = NULL;
	while(scanf("%s", dat) != EOF)
		gentree(&root, dat);

	return 0;
}

/* 木の作成の再帰手続き */
void gentree(tnode **p, char *w) {
	if((*p) == NULL) {
		(*p) = talloc();
		strcpy((*p)->name, w);
		(*p)->left = (*p)->right = NULL;
	} else if(strcmp(w, (*p)->name) < 0) {
		gentree(&((*p)->left), w);
	} else {
		gentree(&((*p)->right), w);
	}
}

/* 記憶領域の取得 */
tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}