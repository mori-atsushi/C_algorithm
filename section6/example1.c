/*
2分探索木の配列表現
*/

#include <stdio.h>
#include <string.h>

#define nil -1
#define MaxSize 100

typedef struct{
	int left; /* 左部分木へのポインタ */
	char name[12];
	int right; /* 右部分木へのポインタ */
} tnode;

int main(void) {
	tnode a[MaxSize] = {{  1, "machilda",   2},
	                    {  3, "Candy"   ,   4},
	                    {  5, "Rolla"   , nil},
	                    {nil, "Ann"     , nil},
	                    {  6, "Emy"     ,   7},
	                    {nil, "Nancy"   , nil},
	                    {nil, "Eluza"   , nil},
	                    {nil, "Lisa"    , nil}};
	char key[12];
	int p;

	printf("Search name --> ");
	scanf("%s", key);
	p = 0;
	while(p != nil) {
		if(strcmp(key, a[p].name) == 0) {
			printf("見つかりました\n");
			break;
		} else if(strcmp(key, a[p].name) < 0) {
			p = a[p].left;
		} else {
			p = a[p].right;
		}
	}

	return 0;
}