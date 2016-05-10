/*
文字列の置き換え(リプレイス)
*/

#include <stdio.h>
#include <string.h>

char *search(char *, char *);
void replace(char *, char *, char *);

int main(void) {
	static char text[] = "This is a pen. That is a pencil.";

	replace(text, "pen", "cap"); /* 同じ長さであること */
	printf("%s\n", text);

	return 0;
}

void replace(char *text, char *key, char *rep) {
	char *p;
	int i;
	p = search(text, key);
	while(p != NULL) {
		for(i = 0; i < (int)strlen(rep); i++) /* 置き換え */
			p[i] = rep[i];
		p = search(p + strlen(key), key);
	}
}

char *search(char *text, char *key) {
	int m, n;
	char *p;

	m = strlen(text);
	n = strlen(key);
	for(p = text; p <= text + m - n; p++) {
		if(strncmp(p, key, n) == 0)
			return p;
	}

	return NULL;
}