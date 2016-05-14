/*
迷路をたどる(経路をスタックに記録する)
*/

#include <stdio.h>

int m[7][7] = {{2, 2, 2, 2, 2, 2, 2},
               {2, 0, 0, 0, 0, 0, 2},
               {2, 0, 2, 0, 2, 0, 2},
               {2, 0, 0, 2, 0, 2, 2},
               {2, 2, 0, 2, 0, 2, 2},
               {2, 0, 0, 0, 0, 0, 2},
               {2, 2, 2, 2, 2, 2, 2}};

int Si, Sj, Ei, Ej, success;
int sp, ri[100], rj[100]; /* 通過位置を入れるスタック */

int visit(int, int);

int main(void) {
	sp = 0; /* スタック・ポインタの初期化 */
	success = 0; /* 脱出に成功したかを示すフラグ */
	Si = 1; Sj = 1; Ei = 5; Ej = 5; /* 入口と出口の位置 */

	printf("\n迷路の探索\n");
	if(visit(Si, Sj) == 0)
		printf("出口は見つかりませんでした\n");
	printf("\n");

	return 0;
}

int visit(int i, int j) {
	int k;

	m[i][j] = 1; /* 訪れた位置に印をつける */
	ri[sp] = i;
	rj[sp] = j;
	sp++;

	if(i == Ei && j == Ej) {
		/* 通過点の表示 */
		for(k = 0; k < sp; k++)
			printf("(%d, %d) ", ri[k], rj[k]);
		success = 1;
	}

	/* 出口に到着しない間迷路を彷徨う */
	if(success != 1 && m[i][j + 1] == 0)
		visit(i, j + 1);
	if(success != 1 && m[i + 1][j] == 0)
		visit(i + 1, j);
	if(success != 1 && m[i][j - 1] == 0)
		visit(i, j - 1);
	if(success != 1 && m[i - 1][j] == 0)
		visit(i - 1, j);

	sp--;
	return success;
}