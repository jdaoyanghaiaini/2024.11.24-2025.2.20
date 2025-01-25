#include"SLTlist.h"
//打印链表
void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}
//创建节点
SLTNode* SLTBuyNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
		//这个是断言函数使用它得包含它的头文件<assert.h>
		//当条件为假时报错，这里用来处理malloc失败的情况；                       
	newnode->next = NULL;
	newnode->date = x;
	return newnode;
}

//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//*pphead不能为空，为空了还删上什么啊~~
	SLTNode* Del = *pphead;//将要删除的节点保存下来，然后将头挪到下一个节点;
	*pphead = (*pphead)->next;
	free(Del);
	Del = NULL;
	//好习惯：释放置空避免野指针，尽管这里用处不大，但建议养成;
}
//头插
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	//看到二级指针先别急，等我下文详细解释；
	//先来想一种极端情况，如果链表为空，那么这个节点便是我们的头;
	//但我们发现链表为空下面也行的通，所以不用考虑那种情况了；
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//找尾
	SLTNode* tail = *pphead;
	SLTNode* prev = tail;
	//这里得找到tail前一个节点才好删除；
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	free(tail);
	tail = NULL;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//考虑极端空链表情况
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//循环遍历找到尾节点:
	else
	{
		SLTNode* tail = *pphead;
		//循环遍历找尾;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}
//在任意一个节点前插入新节点
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead && pos);
	if (pos == *pphead)
	{
		SLTPushFront(pphead,x);
	}
	else
	{
		SLTNode* prev = *pphead;
		SLTNode* newnode = SLTBuyNode(x);
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
//删除任意位置的节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
		assert(pphead && pos);
		//与上面一样考虑特殊情况
		if (pos == *pphead)
		{
			SLTPopFront(pphead);
		}
		else
		{
			SLTNode* prev = pphead;
			while (prev->next)
			{
				prev = prev->next;
			}
			prev->next = pos->next;
			free(pos);
			pos = NULL;
		}
}
//找到某位置
SLTNode* SLTFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//销毁链表
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	SLTNode* Del = cur;
	while (cur)
	{
		Del = cur;
		cur = cur->next;
		free(Del);
		//这里得特别注意顺序，要不然会删少；
	}
	//别忘了将头置为空
	*pphead = NULL;
}
