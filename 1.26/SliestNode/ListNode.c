#include"ListNode.h"
//创造节点
LTNode* LTBuyNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	assert(newnode);
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//初始化节点
//为什么要有一个初始化函数呢？
//单链表都没有~~
//原因：单链表没写哨兵位，而且没有循环，直接创造一个节点就可以，而这里它作为一个循环链表，一开始我们head的prev和next都指向自己，方便设置而已;
LTNode* LTInit()
{
	LTNode* head = LTBuyNode(0);
	head->next = head;
	head->prev = head;
	return head;
}
//打印链表
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;//第一个是哨兵位从第二个开始开始遍历打印;
	printf("<=>head<=>");
	while (cur != phead)//作为一个循环链表它遍历完后会重新回到头节点;
	{
		printf("%d<=>", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
//头插
void LTPushFront(LTNode* phead,LTDateType x)
{
	assert(phead);
	//传一级指针：与单链表不同，在双向循环链表中我们不用改变节点那个指针变量，改变的是节点内指针的信息；
	//具体可以看我画的图
	LTNode* newnode = LTBuyNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
}
//判断链表是否为空
bool LTEmpty(LTNode* phead)
{
	if (phead->next == phead)//当头指向自己说明链表为空；
	{
		return true;
	}
	return false;
}
//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	//链表是否为空呢？写一个函数来判断;
	assert(!LTEmpty(phead));
	LTNode* Del = phead->next;
	phead->next = Del->next;
	Del->next->prev = phead;
	free(Del);
	Del = NULL;
}
//尾插
void LTPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	//找尾:单链表找尾是要遍历，但双向循环不用，因为哨兵位的prev指向的是最后一个节点
	LTNode* newnode = LTBuyNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	LTNode* Del = phead->prev;
	phead->prev = Del->prev;
	Del->prev->next = phead;
	free(Del);
	Del = NULL;
}
//找到某节点
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
//任意位置之前插入
void LTInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	LTNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除任意位置
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	prev->next = pos->next;
	pos->next->prev = prev;
	free(pos);
	pos = NULL;
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