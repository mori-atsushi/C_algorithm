/*
マージ(併合)
*/

#include <stdio.h>

#define M 10
#define N 5

int main(void) {
	int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40},
	    b[] = {6, 11, 25, 33, 35},
	    c[M + N];
	int i, j, p;

	i = j = p = 0;
	/* a[]もb[]とも終わりでない間 */
	while (i < M && j < N) {
		if(a[i] <= b[j])
			c[p++] = a[i++];
		else
			c[p++] = b[j++];
	}

	/* a[]が終わりになるまで */
	while(i < M)
		c[p++] = a[i++];
	/* b[]が終わりになるまで */
	while(j < N)
		c[p++] = b[j++];

	for(i = 0; i < M + N; i++)
		printf("%d ", c[i]);
	printf("\n");

	return 0;
}