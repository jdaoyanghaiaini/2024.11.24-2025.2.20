#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//�ṹ��
typedef struct Slistnode
{
	int x;
	struct Slistnode* next;
}SLTnode;
//��ӡ
void printf_List(SLTnode** pphead);
//����
SLTnode* SLTbuynode(int x);
//β��
void SLTpushback(SLTnode** pphead, int x);
//ͷ��
void SLTpushfront(SLTnode** pphead, int x);
//βɾ
void SLTpopback(SLTnode** pphead);
//ͷɾ
void SLTpophead(SLTnode** pphead);
//����
SLTnode* SLTfind(SLTnode* phead, int x);
//�ڽڵ�ǰ����
void SLTinsertbefore(SLTnode** pphead, SLTnode* pos, int x);
//�ڽڵ�����
void SLTinsertafter(SLTnode* pos, int x);
//ɾ��ĳ���ڵ�
void SLTErase(SLTnode** pphead, SLTnode* pos);
//ɾ��ĳ���ڵ�֮��Ľڵ�(һ��)
void SLTEraseafter(SLTnode* pos);
//��������
void SLIstdestory(SLTnode** pphead);