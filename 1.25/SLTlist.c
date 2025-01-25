#include"SLTlist.h"
//��ӡ����
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
//�����ڵ�
SLTNode* SLTBuyNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
		//����Ƕ��Ժ���ʹ�����ð�������ͷ�ļ�<assert.h>
		//������Ϊ��ʱ����������������mallocʧ�ܵ������                       
	newnode->next = NULL;
	newnode->date = x;
	return newnode;
}

//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//*pphead����Ϊ�գ�Ϊ���˻�ɾ��ʲô��~~
	SLTNode* Del = *pphead;//��Ҫɾ���Ľڵ㱣��������Ȼ��ͷŲ����һ���ڵ�;
	*pphead = (*pphead)->next;
	free(Del);
	Del = NULL;
	//��ϰ�ߣ��ͷ��ÿձ���Ұָ�룬���������ô����󣬵���������;
}
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	//��������ָ���ȱ𼱣�����������ϸ���ͣ�
	//������һ�ּ���������������Ϊ�գ���ô����ڵ�������ǵ�ͷ;
	//�����Ƿ�������Ϊ������Ҳ�е�ͨ�����Բ��ÿ�����������ˣ�
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//��β
	SLTNode* tail = *pphead;
	SLTNode* prev = tail;
	//������ҵ�tailǰһ���ڵ�ź�ɾ����
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	free(tail);
	tail = NULL;
}
//β��
void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//���Ǽ��˿��������
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//ѭ�������ҵ�β�ڵ�:
	else
	{
		SLTNode* tail = *pphead;
		//ѭ��������β;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}
//������һ���ڵ�ǰ�����½ڵ�
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
//ɾ������λ�õĽڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
		assert(pphead && pos);
		//������һ�������������
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
//�ҵ�ĳλ��
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
//��������
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	SLTNode* Del = cur;
	while (cur)
	{
		Del = cur;
		cur = cur->next;
		free(Del);
		//������ر�ע��˳��Ҫ��Ȼ��ɾ�٣�
	}
	//�����˽�ͷ��Ϊ��
	*pphead = NULL;
}
