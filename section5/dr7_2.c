/*
逆ポーランド記法(かっこの処理を含む)
*/

#include <stdio.h>

char stack[50], polish[50];
int pri[256]; /* 優先順位表 */
int sp1, sp2; /* スタック・ポインタ */

int main(void) {
	int i;
	char *p = "(a+b)*(c+d)"; /* 式 */

	/* 優先順位表の作成 */
	for(i = 0; i <= 255; i++)
		pri[i] = 3;
	pri['+'] = pri['-'] = 1;
	pri['*'] = pri['/'] = 2;
	pri['('] = 4;
	pri[')'] = 0;

	/* 番兵 */
	stack[0] = 0;
	pri[0] = -1;

	sp1 = sp2 = 0;
	while(*p != '\0') {
		while(pri[*p] <= pri[stack[sp1]] && stack[sp1] != '(')
			polish[++sp2] = stack[sp1--];
		if(*p != ')')
			stack[++sp1] = *p;
		else
			sp1--;
		p++;
	}

	/* スタックの残りを取り出す */
	for(i = sp1; i > 0; i--)
		polish[++sp2] = stack[i];

	for(i = 1; i <= sp2; i++)
		putchar(polish[i]);
	printf("\n");

	return 0;
}