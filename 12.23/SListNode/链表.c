#include"lianb.h"
//��ӡ
void printf_List(SLTnode** pphead)
{
	SLTnode* pcur = *pphead;
	while (pcur)
	{
		printf("%d->", pcur->x);
		pcur = pcur->next;
	}
}
//����
SLTnode* SLTbuynode(int x)
{
	SLTnode* newnode = (SLTnode*)malloc(sizeof(SLTnode));
	if (newnode == NULL)
	{
		perror("malloc fail");
	}
	newnode->x = x;
	newnode->next = NULL;
	return newnode;
}
//β��
void SLTpushback(SLTnode** pphead, int x)
{

	assert(pphead);
	SLTnode* newnode = SLTbuynode(x);
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
//ͷ��
void SLTpushfront(SLTnode** pphead, int x)
{
	assert(pphead);
	SLTnode* newnode = SLTbuynode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//βɾ
void SLTpopback(SLTnode** pphead)
{
	assert(*pphead && pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTnode* ptail = *pphead;
		SLTnode* prev = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
//ͷɾ
void SLTpophead(SLTnode** pphead)
{
	SLTnode* pcur = *pphead;
	pcur = pcur->next;
	free(*pphead);
	*pphead = pcur;
}
//����
SLTnode* SLTfind(SLTnode* phead, int x)
{
	while (phead)
	{
		if (phead->x == x)
		{
			printf("�ҵ���\n");
			return phead;
		}
		phead = phead->next;
	}
	printf("δ�ҵ�\n");
	return NULL;
}
void SLTinsertbefore(SLTnode** pphead, SLTnode* pos, int x)
{
	SLTnode* temp = *pphead;
	if (temp == pos)
	{
		void SLTpushfront(tmp,x);
	}
	else
	{
		while (temp->next != pos)
		{
			temp = temp->next;
		}
		SLTnode* newnode = SLTbuynode(x);
		newnode->next = pos;
		temp->next = newnode;
	}
}
//�ڵ�ǰ����
void SLTinsertafter(SLTnode* pos,int x)
{
	SLTnode* newnode = SLTbuynode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTErase(SLTnode** pphead, SLTnode* pos)
{
	assert(*pphead && pphead && pos);
	if (pos == *pphead)
	{
		SLTnode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
	SLTnode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}
//ɾ��ĳ�ڵ��Ժ�Ľڵ�
void SLTEraseafter(SLTnode* pos)
{
	assert(pos&&pos->next);
	SLTnode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
//��������
void SLIstdestory(SLTnode** pphead)
{
	assert(pphead && *pphead);
	SLTnode* pcur = *pphead;
	while (pcur)
	{
		SLTnode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}


