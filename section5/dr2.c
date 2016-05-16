/*
キュー(待ち行列)
*/

#include <stdio.h>

#define MaxSize 1000 /* キューサイズ */
int queue[MaxSize]; /* キュー */
int head = 0, tail = 0;
int queuein(int);
int queueout(int *);
void disp(void);

int main(void) {
	int c, n;

	while(printf("]"), (c = getchar()) != EOF) {
		rewind(stdin);
		switch(c) {
			case 'i':
			case 'I':
				printf("data --> ");
				scanf("%d", &n);
				rewind(stdin);
				if(queuein(n) == -1)
					printf("待ち行列がいっぱいです\n");
				break;
			case 'o':
			case 'O':
				if(queueout(&n) == -1)
					printf("待ち行列は空です。\n");
				else
					printf("queue data --> %d\n", n);
			case 'l':
			case 'L':
				disp();
				break;
		}
	}
	return 0;
}

/* キューにデータを入れる手続き */
int queuein(int n) {
	if((tail + 1) % MaxSize != head) {
		queue[tail] = n;
		tail++;
		tail = tail % MaxSize;
		return 0;
	} else {
		return -1;
	}
}

/* キューからデータを取り出す手続き */
int queueout(int *n) {
	if(tail != head) {
		*n = queue[head];
		head++;
		head = head % MaxSize;
		return 0;
	} else {
		return -1;
	}
}

/* 待ち行列の内容を表示する手続き */
void disp(void) {
	int i;

	i = head;
	while(i != tail) {
		printf("%d\n", queue[i]);
		i++;
		i = i % MaxSize;
	}
}