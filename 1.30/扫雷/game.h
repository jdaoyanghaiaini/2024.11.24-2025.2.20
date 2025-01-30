#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9

#define COLS COL+2
#define ROWS ROW+2
#define EASY_COUNT 10
//菜单
void menu();
//游戏本体
void game();
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c, char set);
//展示棋盘
void DisplayBoard(char[ROWS][COLS], int r, int c);
//排雷
void mine_remove(char mine[ROWS][COLS],char show[ROWS][COLS] , int r, int c);
//放雷
void Getmine(char mine[ROWS][COLS], int c, int r);
//安排数字
int Getminenumber(char show[ROWS][COLS], int c, int r);
