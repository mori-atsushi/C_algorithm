/*
文字列の置き換え(リプレイス)
*/

#include <stdio.h>
#include <string.h>

char *search(char *, char *);
void replace(char *, char *, char *);

int main(void) {
	int k;
	static char text[][128] = {"　　　--- サルビアの花 ---",
	                           "いつもいつも思っていた",
	                           "サルビアの花をあなたの部屋の中に",
	                           "投げ入れたくて",
	                           "そして君のベッドに",
	                           "サルビアの紅い花敷き詰めて",
	                           "僕は君を死ぬまで抱きしめていようと",
	                           ""};
	k = 0;
	while(text[k][0] != '\0') {
		replace(text[k], "サルビア", "か す み 草");
		replace(text[k], "紅", "白");
		printf("%s\n", text[k]);
		k++;
	}

	return 0;
}

void replace(char *text, char *key, char *rep) {
	char *p, buf[128];

	p = search(text, key);
	while(p != NULL) {
		*p = '\0';
		strcpy(buf, p + strlen(key));
		strcat(text, rep);
		strcat(text, buf);
		p = search(p + strlen(rep), key);
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