#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef struct ListNode LTNode;
typedef int LTDateType;
struct ListNode {
	LTNode* next;
	LTNode* prev;
	LTDateType date;
};
//��������
void LTDestroy(LTNode* phead);
//ʵ�ֳ�ʼ��
LTNode* LTInit();
//�����ڵ�
LTNode* LTBuyNode(LTDateType x);
//βɾ
void LTPopBack(LTNode* phead);
//β��ڵ�
void LTPushBack(LTNode* phead, LTDateType x);
//��ӡ����
void LTPrint(LTNode* phead);
//ͷ��
void LTPushFront(LTNode* phead,int x);
//ͷɾ
void LTPopFront(LTNode* phead);
//�ж������Ƿ�Ϊ��
bool LTEmpty(plist);
//���ҽڵ�
LTNode* LTFind(LTNode* phead, LTDateType x);
//ĳλ��֮ǰ����ڵ�
void LTInsert(LTNode* pos, LTDateType x);
//ɾ��ĳ�ڵ�
void LTErase(LTNode* pos);