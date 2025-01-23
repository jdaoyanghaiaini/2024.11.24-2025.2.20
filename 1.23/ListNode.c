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
	assert(phead);
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
	assert(phead);
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
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
}
//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode* Del = phead->next;
	phead->next = Del->next;
	Del->next->prev = phead;
	free(Del);
}
//尾插
void LTPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	LTNode* tail = phead->prev;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(phead->prev);
}
//判断链表是否为空
bool LTEmpty(LTNode* phead)
{
	if (phead->next == phead)
	{
		return true;
	}
	return false;
}
//查找节点
LTNode* LTFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//某位置之前插入节点
void LTInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;

	
}
//删除某节点
void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
}