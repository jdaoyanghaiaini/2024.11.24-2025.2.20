#include"SList.h"
//�����ڵ�
SLTNode* BuySLTNode(SLTDateType x)
{
	SLTNode* newnode = NULL;
	SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
	assert(tmp);
	newnode = tmp;
	newnode->date = x;
	newnode->next = NULL;
	//��ʼ���ǵý�newnode��Ϊ�գ�
	return newnode;
}
//��ӡ�ڵ�
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
//β��ڵ�
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
		//��β
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
//ͷ��ڵ�
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pphead;
	newnode->date = x;
	*pphead = newnode;
	//�ǵý�ͷָ���½ڵ㣻
}
//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* deletenode = *pphead;
	*pphead = deletenode->next;
	deletenode->next = NULL;
	free(deletenode);
}
//βɾ
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
		//��β
		while (tail->next)
		{
			prev = tail;//��¼���һ���ڵ��ǰһ��λ�ã�����Ұָ��
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		//ע�⵱ֻ��һ���ڵ��ʱ��ȥҪ�������۲�Ȼ���������ÿ�ָ�룻
	}
}
//���ҽڵ�(�ҵ��ýڵ�λ�÷�������ָ��)
SLTNode* SLTNodeFind(SLTNode* phead, SLTDateType x)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur->date != x)
	{
		cur = cur->next;
		if (cur == NULL)
		{
			//���û���ҵ��ͷ��ؿ�ָ�룻
			printf("û�ҵ�\n");
			return NULL;
		}
	}
	return cur;
}
//��������ָ���ڵ��ǰ��
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead && pos);
	//pphead����Ϊ�գ��������ֵ���ͻ����
	//ͷ������⿼�ǣ��н����ÿ�ָ������
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
//ɾ��posλ��
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
		//pos = NULL;   pos������Ϊ�������壬�Ƕ���ָ��
	}
}
