/*
レベル毎の2分探索機のトラバーサル
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct temp{
	struct temp *left;
	char name[12];
	struct temp *right;
} tnode;

typedef struct{		/* 接続関係を示す構造体 */
	tnode *node;	/* 子ノード */
	char *parent;	/* 親の名前 */
	char direct;	/* 親の左の子か右の子かを示す */
} connect;

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

/* レベル毎の木のトラバーサル */
void treewalk(tnode *p) {
	connect q[128], w[128];
	int i, child, n, level;

	child = 1;
	level = 0;
	q[0].node = p;
	q[0].parent = "root";
	q[0].direct = ' ';

	do {
		n = 0;
		printf("level %d:\n", level);
		for(i = 0; i < child; i++) {
			printf("%12s->%c:%12s\n", q[i].parent, q[i].direct, q[i].node->name); /* ノードの表示 */
			/* 1つ下のレベルの子へのポインタをスタックに積む */
			if(q[i].node->left != NULL) {
				w[n].parent = q[i].node->name;
				w[n].direct = 'l';
				w[n].node = q[i].node->left;
				n++;
			}

			if(q[i].node->right != NULL) {
				w[n].parent = q[i].node->name;
				w[n].direct = 'r';
				w[n].node = q[i].node->right;
				n++;
			}
		}
		printf("\n");
		child = n; /* 1つ下のレベルの子の数 */
		for(i = 0; i < child; i++)
			q[i] = w[i];
		level++;
	} while(child != 0);
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