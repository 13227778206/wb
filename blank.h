#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct blank {
	int x;
	int y;
	char* profile;
}blank;
//void move(snake*Snake, int x, int y) {
//	Snake->x = x;
//	Snake->y = y;
//}
void printblank(blank*blank) {
	char a[] = { "¡ö" };
	blank->profile = a;
	printf("%s ", blank->profile);

}