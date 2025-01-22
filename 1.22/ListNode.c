#include"ListNode.h"
//��ʼ��
LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	phead->next = phead;
	phead->next = phead;
	return phead;
}
//����ڵ�
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
//��ӡ����
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
//ͷ��
void LTPushFront(LTNode* phead,int x)
{
	LTNode* newnode = LTBuyNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
}
//ͷɾ
void LTPopFront(LTNode* phead)
{
	LTNode* Del = phead->next;
	phead->next = Del->next;
	Del->next->prev = phead;
	free(Del);
}