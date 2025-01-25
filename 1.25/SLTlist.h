#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct SLTlistNode SLTNode;//�Խṹ��������������������ʹ�ã�
typedef int SLTDateType;
//���ｫint������Ϊ�˷����Ժ���Ĵ洢���ݵ�����
//����Ҫ���渡���������ｫint��Ϊfloat�����ˣ�
struct SLTlistNode {
	SLTNode* next;//ָ�������¸��ڵ�ĵ�ַ
	SLTDateType date;//������洢���ݣ�
};
//��ӡ����
void SLTPrint(SLTNode* phead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDateType x);
//�����ڵ�
SLTNode* SLTBuyNode(SLTDateType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//β��
void SLTPushBack(SLTNode** pphead, SLTDateType x);
//������һ���ڵ�ǰ�����½ڵ�
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//ɾ������λ�õĽڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);
//�ҵ�ĳλ��
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);
//��������
void SLTDestroy(SLTNode** pphead);