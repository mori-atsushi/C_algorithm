/*
質疑応答と決定木(配列表現)
*/

#include <stdio.h>

#define Max 100
#define nil -1

typedef struct {
	int left;
	char node[30];
	int right;
} tnode;

int getch(void) {
	rewind(stdin);
	return getchar();
}

int main(void) {
	tnode a[Max] = {{1		, "芸能人ですか"	, 2},
	                {2		, "歌手ですか"	, 4},
	                {nil	, "吉田 茂"		, nil},
	                {nil	, "井上 陽水"		, nil},
	                {5		, "女優ですか"	, 6},
	                {nil	, "中山 美穂"		, nil},
	                {nil	, "久米 宏"		, nil}};
	int p, lp = 6, c;

	do {
		p = 0;
		while(a[p].left != nil) {
			printf("\n%s y / n ", a[p].node);
			c = getch();
			if(c == 'y' || c == 'Y')
				p = a[p].left;
			else
				p = a[p].right;
		}

		printf("\n答えは%sです。\n正しいですか？ y / n ", a[p].node);
		c = getch();

		if(c == 'n' || c == 'N') {
			a[lp + 1] = a[p];

			printf("\nあなたの考えは？ ");
			scanf("%s", a[lp+2].node);
			a[lp + 2].left = a[lp + 2].right = nil;
			rewind(stdin);

			printf("%s と %s を区別する質問は？ ", a[lp + 1].node, a[lp + 2].node);
			scanf("%s", a[p].node);
			printf("yesの項目は %s で良いですか？ y / n ", a[lp + 1].node);
			c = getch();

			if(c == 'Y' || c == 'y') {
				a[p].left = lp + 1;
				a[p].right = lp + 2;
			} else {
				a[p].left = lp + 2;
				a[p].right = lp + 1;
			}
			lp = lp + 2;
		}
	} while(printf("\n 続けますか？ y / n "), c = getch(), c == 'y' || c == 'Y');

	printf("\n");

	return 0;
}