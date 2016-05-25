/*
リストを用いたハッシュ(終端に追加)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TableSize 1000
#define ModSize 1000

int hash(char *);

typedef struct temp {
	char name[20]; /* 名前 */
	char tel[20]; /* 電話番号 */
	struct temp *pointer; /* 次データへのポインタ */
} tfield;

tfield *dat[TableSize];

tfield *talloc(void);

int main(void) {
	int n;
	char key[12];
	tfield *p, *q;

	/* ポインタ・テーブルの初期化 */
	for(n = 0; n < TableSize; n++)
		dat[n] = NULL;

	printf("名前 電話番号\n");
	while(p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
		if(!strcmp(p->name, "q"))
			break;
		n = hash(p->name); /* ハッシング */
		if(dat[n] == NULL) { /* 空の時 */
			dat[n] = p;	
			p->pointer = NULL;
		} else { /* かち合った時 */
			q = dat[n];
			while(q->pointer != NULL) /* 終端へ追加 */
				q = q->pointer;
			q->pointer = p;
			p->pointer = NULL;
		}

	}

	rewind(stdin);
	printf("\n探索するデータを入力してください\n");
	while(scanf("%s", key) != EOF) {
		n = hash(key);
		p = dat[n];
		while(p != NULL) {
			if(strcmp(key, p->name) == 0) {
				printf("%15s%15s\n", p->name, p->tel);
				break;
			}
			p = p->pointer;
		}
		if(p == NULL)
			printf("データが見つかりませんでした。\n");

	}
	return 0;
}

/* ハッシュ関数 */
int hash(char *s) {
	int n;

	n = strlen(s);
	return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % ModSize;
}

/* 記憶領域の確保 */
tfield *talloc(void) {
	return (tfield *)malloc(sizeof(tfield));
}