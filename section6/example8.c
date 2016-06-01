/*
式の木
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	struct temp *left;
	char ope;
	struct temp *right;
} tnode;

tnode *talloc(void);
tnode *gentree(tnode * , char *);
void prefix(tnode *);
void infix(tnode *);
void postfix(tnode *);

int main(void) {
	tnode *root;
	char expression[] = "ab*cd+e/-";

	root = NULL;
	root = gentree(root, expression);

	printf("\nprefix  = ");
	prefix(root);
	printf("\ninfix   = ");
	infix(root);
	printf("\npostfix = ");
	postfix(root);
	printf("\n");

	return 0;
}

tnode *gentree(tnode *p, char *w) {
	int n;

	n = strlen(w);
	p = talloc();
	p->ope = w[n - 1];
	w[n - 1] = '\0';
	if(!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/')) {
		p->left = p->right = NULL;
	} else {
		p->right = gentree(p->right, w);
		p->left = gentree(p->left, w);
	}

	return p;
}

/* 接頭形 */
void prefix(tnode *p) {
	if(p != NULL) {
		putchar(p->ope);
		prefix(p->left);
		prefix(p->right);
	}
}

/* 挿入形 */
void infix(tnode *p) {
	if(p != NULL) {
		infix(p->left);
		putchar(p->ope);
		infix(p->right);
	}
}

/* 設備形 */
void postfix(tnode *p) {
	if(p != NULL) {
		postfix(p->left);
		postfix(p->right);
		putchar(p->ope);
	}
}

/* 記憶領域の取得 */
tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}