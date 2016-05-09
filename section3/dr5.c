/*
マージ(併合)
*/

#include <stdio.h>

#define M 13
#define N 5
#define MaxEof 9999 /* 番兵 */

int main(void) {
	int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40, 45, 50, 60, MaxEof},
	    b[] = {6, 11, 25, 33, 35, MaxEof},
	    c[M + N];
	int i, j, p;

	i = j = p = 0;
	while(a[i] != MaxEof || b[j] != MaxEof) {
		if(a[i] <= b[j])
			c[p++] = a[i++];
		else
			c[p++] = b[j++];
	}

	for(i = 0; i < M + N; i++)
		printf("%d ", c[i]);
	printf("\n");
}