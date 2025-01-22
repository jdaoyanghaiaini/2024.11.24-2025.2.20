#include"ListNode.h"
//初始化
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	phead->next = phead;
	phead->next = phead;
	return phead;
}
//创造节点
LTNode* LTBuyNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->date = x;
	return newnode;
}
//打印链表
void LTPrint(LTNode* phead)
{
	printf("<=>head<=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->date);
		cur = cur->next;
	}
	printf("\n");
}

//销毁链表
void LTDestroy(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
//头插
void LTPushFront(LTNode* phead,int x)
{
	LTNode* newnode = LTBuyNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
}
//头删
void LTPopFront(LTNode* phead)
{
	LTNode* Del = phead->next;
	phead->next = Del->next;
	Del->next->prev = phead;
	free(Del);
}