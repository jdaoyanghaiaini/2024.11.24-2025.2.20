#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode LTNode;
typedef int LTDateType;
struct ListNode {
	LTNode* next;
	LTNode* prev;
	LTDateType date;
};
//ʵ�ֳ�ʼ��
LTNode* LTInit();
//ɾ������
void LTDestroy();
//�����ڵ�
LTNode* LTBuyNode(LTDateType x);
//βɾ

//β��ڵ�
void LTPushBack(LTNode* phead, LTDateType x);
//��ӡ����
void LTPrint(LTNode* phead);
//ͷ��
void LTPushFront(LTNode* phead,int x);
//ͷɾ
void LTPopFront(LTNode* phead);