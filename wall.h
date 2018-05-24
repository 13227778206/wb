#pragma once
#include <stdio.h>
#include<stdlib.h>
#include"snake.h"
#include"blank.h"
#include<windows.h>
#include <conio.h>
HANDLE hout;
typedef struct wall {
	char* type;
	int crash;
	int* x;
	int* y;
	int size;
	int capacity;
}wall;
//void build(int width,int hight)；
void build(wall* walls, int width, int hight) {
	COORD coord;
	char a[] = { "■" };
	walls->type = a;
	walls->capacity = width * hight;
	blank blank;
	walls->x = (int*)malloc(sizeof(int)*walls->capacity);
	walls->y = (int*)malloc(sizeof(int)*walls->capacity);
	snake snake;
	snake.x = (int*)malloc(sizeof(int)*walls->capacity * 10);;
	snake.y = (int*)malloc(sizeof(int)*walls->capacity * 10);
	int sum = 0;
	snake.x[sum] = 3;
	snake.y[sum] = 3;
	int key = 0;
	int c = 0;
	int number1 = rand() % width;
	int number2 = rand() % hight;
	blank.x = number1;
	blank.y = number2;
	while (1) {
		//hout = GetStdHandle(STD_OUTPUT_HANDLE);
		walls->size = 0;
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < hight; j++) {
				
				

					if ((j == 0 || j == width - 1) || (i == 0 || i == hight - 1)) {
						
						printf("%s ", walls->type);
						walls->x[walls->size] = i;
						walls->y[walls->size] = j;
						walls->size++;
						if (i == 10 && j == width - 1) {
							printf("操作方式：w,a,s，d控制蛇上下左右移动");
						}
						if (i == 12 && j == width - 1) {
							printf("当前分数:      %d",c);
						}
					}
					  if ((j > 0 && j < width - 1) && (i > 0 && i < hight - 1)) {
						  
						
						//if (snake.x[sum] == i && snake.y[sum] == j && sum < 1) {
						//	printsnake(&snake);
						//}   
						  
						for (int k = 0; k <=c; k++) {
								if (blank.x == i && blank.y == j&&k==0) {
									printblank(&blank);
								}
							else if (snake.x[sum - k] == i && snake.y[sum - k] == j) {
								printsnake(&snake);
							}
							else if (k == 0)
								printf("   ");
							
						
						}
							
						
							//(snake.x[sum - k] != i || snake.y[sum - k] != j) && (blank.x != i || blank.y != j)
						
					}

				
				
			}
			printf("\n");
		}

		walls->capacity = walls->size;



		key = getchar();
		if (key == 119) {
			sum++;
			snake.x[sum] = --snake.x[sum - 1];
			snake.y[sum] = snake.y[sum - 1];
		}
		if (key == 97) {
			sum++;
			snake.y[sum] = --snake.y[sum - 1];
			snake.x[sum] = snake.x[sum - 1];
		}
		if (key == 100) {
			sum++;
			snake.y[sum] = ++snake.y[sum - 1];
			snake.x[sum] = snake.x[sum - 1];
		}
		if (key == 115) {
			sum++;
			snake.x[sum] = ++snake.x[sum - 1];
			snake.y[sum] = snake.y[sum - 1];
		}
		if (snake.x[sum] == blank.x&&snake.y[sum] == blank.y) {
			number1 = rand() % width;
			number2 = rand() % hight;
			blank.x = number1;
			blank.y = number2;
			c++;
		}
		system("cls");
	}
}
