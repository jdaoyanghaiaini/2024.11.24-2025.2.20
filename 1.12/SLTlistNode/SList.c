#include"SList.h"
//创建节点
SLTNode* BuySLTNode(SLTDateType x)
{
	SLTNode* newnode = NULL;
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	newnode = tmp;
	newnode->date = x;
	newnode->next = NULL;
	//初始化记得将newnode置为空；
	return newnode;
}
//打印节点
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
//尾插节点
void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = BuySLTNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		//找尾
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
//头插节点
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	newnode->date = x;
	*pphead = newnode;
	//记得将头指向新节点；
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* deletenode = *pphead;
	*pphead = deletenode->next;
	deletenode->next = NULL;
	free(deletenode);
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	if((*pphead)->next == NULL)
	{
		free(*pphead);
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		//找尾
		while (tail->next)
		{
			prev = tail;//记录最后一个节点的前一个位置，避免野指针
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		//注意当只有一个节点的时候不去要特殊讨论不然产生解引用空指针；
	}
}
//查找节点(找到该节点位置返回它的指针)
SLTNode* SLTNodeFind(SLTNode* phead, SLTDateType x)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur->date != x)
	{
		cur = cur->next;
		if (cur == NULL)
		{
			//如果没找找到就返回空指针；
			printf("没找到\n");
			return NULL;
		}
	}
	return cur;
}
//插入链表指定节点的前面
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead && pos);
	//pphead不能为空，比如错误传值，就会出错；
	//头插得特殊考虑，有解引用空指针的情况
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySLTNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
//删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		//pos = NULL;   pos这里置为空无意义，非二级指针
	}
}
