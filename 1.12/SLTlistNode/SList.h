#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDateType;
typedef struct SLTListNode SLTNode;
struct SLTListNode
{
	SLTDateType date;
	SLTNode* next;
};
//��ӡ�ṹ��
void SLTPrint(SLTNode* phead);
//�����ڵ�
SLTNode* BuySLTNode(SLTDateType x);
//β��ڵ�
void SLTPushBack(SLTNode** pphead, SLTDateType x);
//ͷ��ڵ�
void SLTPushFront(SLTNode** pphead, SLTDateType x);
//ͷɾ�ڵ�
void SLTPopFront(SLTNode** pphead);
//βɾ�ڵ�
void SLTPopBack(SLTNode** pphead);
//���ҽڵ�(�ҵ��ýڵ�λ�÷�������ָ��)
SLTNode* SLTNodeFind(SLTNode* phead, SLTDateType x);
//��������ڵ��ǰ��
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos);
