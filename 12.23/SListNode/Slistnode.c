//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<assert.h>
//typedef struct STU
//{
//	char name[15];
//	int old;
//	struct STU* next;
//}STU;
//void print_List(STU** pphead)
//{
//	STU* pcur = *pphead;
//	while (pcur)
//	{
//		printf("%s %d\n", (pcur->name), (pcur->old));
//		pcur = pcur->next;
//	}
//}
//STU* SLTbuynode()
//{
//	STU* newnode = (STU*)malloc(sizeof(STU));
//	newnode->next = NULL;
//	printf("输入你的姓名：\n");
//	fgets(newnode->name, 15, stdin);
//	printf("输入你的年龄：\n");
//	scanf("%d", &(newnode->old));
//	while ((getchar()) != '\n');
//	return newnode;
//}
//void SLTpushback(STU** pphead)
//{
//	STU* newnode=SLTbuynode();
//	if (*pphead==NULL)
//	{
//		*pphead = newnode;
//	}
//	else
//	{
//		STU* ptail = *pphead;
//		while (ptail->next)
//		{
//			ptail = ptail->next;
//		}
//		ptail->next = newnode;
//	}
//}
//int main()
//{
//	char select[15];
//	STU* plist = NULL;
//	do
//	{
//		SLTpushback(&plist);
//		printf("输入over退出，任意字母继续\n");
//		fgets(select, 10, stdin);
//		if (select[strlen(select) - 1] == '\n') {
//			select[strlen(select) - 1] = '\0';
//		}
//	} while (strcmp(select,"over"));
//	print_List(&plist);
//	return 0;
//}