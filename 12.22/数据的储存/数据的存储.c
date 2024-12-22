#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
////大小端判断；
//int main()
//{
//	int n = 12345678;
//		if (*(char*)&n==78)
//	    {
//		printf("小端");
//	    }
//	else
//		printf("大端");
//	return 0;
//}
//例题分享
// 1.
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//2. 
//char* GetMemory()
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//这里写一段代码与上文作比较
//int* Test()
//{
//    int a = 9;
//    return &a;
//}
//int main()
//{
//    int* n = Test();
//    //printf("hehe");
//    printf("%d", *n);
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>]
#include<assert.h>
typedef struct Slistnode
{
	int x;
	struct Slistnode* next;
}SLTnode;
void printf_List(SLTnode** pphead)
{
	SLTnode* pcur = *pphead;
	while (pcur->next)
	{
		printf("%d->", pcur->x);
		pcur = pcur->next;
	}
}
SLTnode* Sltbuynode(int* x)
{
	SLTnode* newnode = (SLTnode*)malloc(sizeof(SLTnode));
	newnode->next = NULL;
	newnode->x=x;
	return newnode;
}
void SLTpushback(SLTnode** pphead, int x)
{
	
	assert(pphead);
	SLTnode* newnode = Sltbuynode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTnode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}
void SLTpushfront(SLTnode** pphead,int x)
{
	assert(pphead);
	SLTnode* newnode= Sltbuynode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
int main()
{
	SLTnode* head = NULL;
	SLTpushback(&head, 1);
	SLTpushback(&head, 2);
	SLTpushback(&head, 3);
	SLTpushback(&head, 4);
	SLTpushback(&head, 5);
	SLTpushfront(&head,6);
	SLTpushfront(&head, 7);
	printf_List(&head);
	return 0;
}