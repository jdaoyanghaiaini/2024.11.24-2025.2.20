#include"ListNode.h"
//����ڵ�
LTNode* LTBuyNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	assert(newnode);
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//��ʼ���ڵ�
//ΪʲôҪ��һ����ʼ�������أ�
//������û��~~
//ԭ�򣺵�����ûд�ڱ�λ������û��ѭ����ֱ�Ӵ���һ���ڵ�Ϳ��ԣ�����������Ϊһ��ѭ������һ��ʼ����head��prev��next��ָ���Լ����������ö���;
LTNode* LTInit()
{
	LTNode* head = LTBuyNode(0);
	head->next = head;
	head->prev = head;
	return head;
}
//��ӡ����
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;//��һ�����ڱ�λ�ӵڶ�����ʼ��ʼ������ӡ;
	printf("<=>head<=>");
	while (cur != phead)//��Ϊһ��ѭ�������������������»ص�ͷ�ڵ�;
	{
		printf("%d<=>", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
//ͷ��
void LTPushFront(LTNode* phead,LTDateType x)
{
	assert(phead);
	//��һ��ָ�룺�뵥����ͬ����˫��ѭ�����������ǲ��øı�ڵ��Ǹ�ָ��������ı���ǽڵ���ָ�����Ϣ��
	//������Կ��һ���ͼ
	LTNode* newnode = LTBuyNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
}
//�ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	if (phead->next == phead)//��ͷָ���Լ�˵������Ϊ�գ�
	{
		return true;
	}
	return false;
}
//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	//�����Ƿ�Ϊ���أ�дһ���������ж�;
	assert(!LTEmpty(phead));
	LTNode* Del = phead->next;
	phead->next = Del->next;
	Del->next->prev = phead;
	free(Del);
	Del = NULL;
}
//β��
void LTPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	//��β:��������β��Ҫ��������˫��ѭ�����ã���Ϊ�ڱ�λ��prevָ��������һ���ڵ�
	LTNode* newnode = LTBuyNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
//βɾ
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
//�ҵ�ĳ�ڵ�
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
//����λ��֮ǰ����
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
//ɾ������λ��
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	prev->next = pos->next;
	pos->next->prev = prev;
	free(pos);
	pos = NULL;
}
//��������
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