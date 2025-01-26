#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef struct ListNode LTNode;
typedef int LTDateType;
struct ListNode
{
	LTDateType date;
	LTNode* next;
	LTNode* prev;	
};
//����ڵ�
LTNode* LTBuyNode(LTDateType x);
//��ʼ���ڵ�
LTNode* LTInit();
//��ӡ�ڵ�
void LTPrint(LTNode* phead);
//ͷ��
void LTPushFront(LTNode* phead,LTDateType x);
//ͷɾ
void LTPopFront(LTNode* phead);
//�ж������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead);
//β��
void LTPushBack(LTNode* phead, LTDateType x);
//βɾ
void LTPopBack(LTNode* phead);
//�ҵ�ĳ�ڵ�
LTNode* LTFind(LTNode* phead, LTDateType x);
//����λ��֮ǰ����
void LTInsert(LTNode* pos, LTDateType x);
//ɾ������λ��
void LTErase(LTNode* pos);
//��������
void LTDestroy(LTNode* phead);
