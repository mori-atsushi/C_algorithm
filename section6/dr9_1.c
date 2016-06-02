/*
質疑応答と決定木(配列表現)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct temp{
	struct temp *left;
	char node[30];
	struct temp *right;
} tnode;

tnode *talloc(void);
int getch(void) {
	rewind(stdin);
	return getchar();
}

int main(void) {
	tnode *root, *p, *q1, *q2;
	int c;

	root = talloc();
	printf("初期ノード？ ");
	scanf("%s", root->node);
	root->left = root->right = NULL;

	do {
		p = root;
		while(p->left != NULL) {
			printf("\n%s y / n ", p->node);
			c = getch();
			if(c == 'y' || c == 'Y')
				p = p->left;
			else
				p = p->right;
		}

		printf("\n答えは%sです。\n正しいですか？ y / n ", p->node);
		c = getch();

		if(c == 'n' || c == 'N') {
			q1 = talloc();
			*q1 = *p;

			q2 = talloc();
			printf("\nあなたの考えは？ ");
			scanf("%s", q2->node);
			q2->left = q2->right = NULL;
			rewind(stdin);

			printf("%s と %s を区別する質問は？ ", q1->node, q2->node);
			scanf("%s", p->node);
			printf("yesの項目は %s で良いですか？ y / n ", q1->node);
			c = getch();

			if(c == 'Y' || c == 'y') {
				p->left = q1;
				p->right = q2;
			} else {
				p->left = q2;
				p->right = q1;
			}
		}
	} while(printf("\n 続けますか？ y / n "), c = getch(), c == 'y' || c == 'Y');

	printf("\n");

	return 0;
}

tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}