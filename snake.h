#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct snake {
	struct  snake *snakehead;
	struct  snake *snakebody;
	char *profile;
	int *x;
	int *y;
	int size;
}snake;
//void move(snake*Snake, int x, int y) {
//	Snake->x = x;
//	Snake->y = y;
//}
void printsnake(snake*Snake) {
	char a[] = { "¡ö" };
	Snake->profile = a;
	printf("%s ", Snake->profile);

}