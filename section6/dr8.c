/*
式の木を用いた式の計算
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	struct temp *left;
	int ope;
	struct temp *right;
} tnode;

tnode *talloc(void);
tnode *gentree(tnode * , char *);
void postfix(tnode *);

int main(void) {
	tnode *root;
	char expression[] = "53*64+2/-";

	root = NULL;
	root = gentree(root, expression);

	postfix(root); /* 式の計算 */
	printf("value = %d\n", root->ope);

	return 0;
}

tnode *gentree(tnode *p, char *w) {
	int n;

	n = strlen(w);
	p = talloc();
	if('0' <= w[n - 1] && w[n - 1] <= '9')
		p->ope = w[n - 1] - '0';
	else
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

/* 設備形 */
void postfix(tnode *p) {
	if(p != NULL) {
		postfix(p->left);
		postfix(p->right);
		switch(p->ope) {
			case '+':
				p->ope = (p->left->ope) + (p->right->ope);
				break;
			case '-':
				p->ope = (p->left->ope) - (p->right->ope);
				break;
			case '*':
				p->ope = (p->left->ope) * (p->right->ope);
				break;
			case '/':
				p->ope = (p->left->ope) / (p->right->ope);
				break;
		}
	}
}

/* 記憶領域の取得 */
tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}