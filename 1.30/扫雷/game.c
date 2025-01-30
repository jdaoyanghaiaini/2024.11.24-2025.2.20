#include"game.h"
//菜单
void menu()
{
	printf("***********************************\n");
	printf("************* 1. play *************\n");
	printf("************* 0. exit *************\n");
	printf("***********************************\n");
}
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
	int i = 0;
	for (i = 0; i <r ; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			board[i][j] = set;
		}
	}
}
//展示棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	printf("\n--------扫雷--------\n");
	int i = 0;
	for (i = 0; i <= c; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= r; i++)
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= c; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//放雷
void Getmine(char mine[ROWS][COLS], int r, int c)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % r+1;
		int y = rand() % c+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//排雷
void mine_remove(char mine[ROWS][COLS],char show[ROWS][COLS], int r, int c)
{
	int x = 0, y = 0;
	int count = 0;
	while (1)
	{
		printf("请选择你要排除的坐标,用空格隔开:\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] != '*')
			{
				printf("已排查，重新输入:\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("你失败了!:\n");
				break;
			}
			else
			{
				show[x][y] = Getminenumber(mine, x, y)+'0';
				count++;
			}
			DisplayBoard(mine, ROW, COL);
			DisplayBoard(show, ROW, COL);
		}
		else
		{
			printf("非法坐标,重新输入;\n");
		}
		if (count == COL * ROW - EASY_COUNT)
		{
			break;
		}
	}
}
//安排数字
int Getminenumber(char mine[ROWS][COLS], int x, int y)
{
	return mine[x + 1][y] + mine[x - 1][y] + mine[x][y + 1] + mine[x + 1][y + 1] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x - 1][y - 1] + mine[x + 1][y - 1] - 8 * '0';
}