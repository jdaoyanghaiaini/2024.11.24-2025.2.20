#include"game.h"
//�˵�
void menu()
{
	printf("***********************************\n");
	printf("************* 1. play *************\n");
	printf("************* 0. exit *************\n");
	printf("***********************************\n");
}
//��ʼ������
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
//չʾ����
void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	printf("\n--------ɨ��--------\n");
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
//����
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
//����
void mine_remove(char mine[ROWS][COLS],char show[ROWS][COLS], int r, int c)
{
	int x = 0, y = 0;
	int count = 0;
	while (1)
	{
		printf("��ѡ����Ҫ�ų�������,�ÿո����:\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] != '*')
			{
				printf("���Ų飬��������:\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("��ʧ����!:\n");
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
			printf("�Ƿ�����,��������;\n");
		}
		if (count == COL * ROW - EASY_COUNT)
		{
			break;
		}
	}
}
//��������
int Getminenumber(char mine[ROWS][COLS], int x, int y)
{
	return mine[x + 1][y] + mine[x - 1][y] + mine[x][y + 1] + mine[x + 1][y + 1] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x - 1][y - 1] + mine[x + 1][y - 1] - 8 * '0';
}