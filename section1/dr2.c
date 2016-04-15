/*
暗号の解読
*/

#include <stdio.h>

int main(void) {
	char table[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
	                'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
	                'L', 'Z', 'X', 'C', 'V' ,'B', 'N', 'M', '?'};
	char *p, *ango = "KSOIDHEPZ";
	int index;

	p = ango;
	while(*p != '\0') {
		if('A' <= *p && *p <= 'Z')
			index = *p - 'A';
		else
			index = 26;
		putchar(table[index]);
		p++;
	}
	printf("\n");

	return 0;
}