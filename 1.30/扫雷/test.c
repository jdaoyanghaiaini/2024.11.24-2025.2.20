#include"game.h"
//��Ϸ����
void game()
{
	//��ʼ������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//չʾ����
	DisplayBoard(mine,ROW,COL );
	DisplayBoard(show,ROW,COL);
	//����
	Getmine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//����
	mine_remove(mine,show, ROW, COL);
}
void Test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������ѡ��:\n");
			break;
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(NULL));
	Test();
}