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
//�˵�
void menu();
//��Ϸ����
void game();
//��ʼ������
void InitBoard(char board[ROWS][COLS], int r, int c, char set);
//չʾ����
void DisplayBoard(char[ROWS][COLS], int r, int c);
//����
void mine_remove(char mine[ROWS][COLS],char show[ROWS][COLS] , int r, int c);
//����
void Getmine(char mine[ROWS][COLS], int c, int r);
//��������
int Getminenumber(char show[ROWS][COLS], int c, int r);
