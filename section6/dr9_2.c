/*
木(動的表現)のディスクへの保存
*/

#include <stdio.h>
#include <stdlib.h>

#define Rec 34L
#define Leaf -1
FILE *fp;

typedef struct temp{
	struct temp *left;
	char node[30];
	struct temp *right;
} tnode;

tnode *talloc(void);
tnode *readtree(tnode *);
void writetree(tnode *);
int getch(void) {
	rewind(stdin);
	return getchar();
}

int main(void) {
	tnode *root, *p, *q1, *q2;
	int c;

	if((fp = fopen("dbase.dat", "r")) == NULL) {
		root = talloc();
		printf("初期ノード？ ");
		scanf("%s", root->node);
		root->left = root->right = NULL;		
	} else {
		root = readtree(root);
		fclose(fp);
	}

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

	if((fp = fopen("dbase.dat", "w")) != NULL) {
		writetree(root);
		fclose(fp);
	}

	return 0;
}

/* ファイルから木をリード */
tnode *readtree(tnode *p) {
	int flag;

	p = talloc();
	fscanf(fp, "%30s%4d", p->node, &flag);
	if(flag == Leaf) {
		p->left = p->right = NULL;
	} else {
		p->left = readtree(p->left);
		p->right = readtree(p->right);
	}
	return p;
}

/* ファイルに木をライト */
void writetree(tnode *p) {
	if(p != NULL) {
		if(p->left == NULL)
			fprintf(fp, "%30s%4d", p->node, Leaf);
		else
			fprintf(fp, "%30s%4d", p->node, !Leaf);
		writetree(p->left);
		writetree(p->right);
	}
}

/* 記憶領域の取得 */
tnode *talloc(void) {
	return (tnode *)malloc(sizeof(tnode));
}