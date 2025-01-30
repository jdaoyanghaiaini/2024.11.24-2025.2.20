#include"game.h"
//游戏本体
void game()
{
	//初始化棋盘
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//展示棋盘
	DisplayBoard(mine,ROW,COL );
	DisplayBoard(show,ROW,COL);
	//放雷
	Getmine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//排雷
	mine_remove(mine,show, ROW, COL);
}
void Test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新选择:\n");
			break;
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(NULL));
	Test();
}