#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int HpDateType;
typedef struct Heap {
	HpDateType *a;
	int capacity;
	int size;
}HP;
//��ʼ����
void HeapInit(HP* php);
//��Ѳ���
void HeapPush(HP* php, HpDateType x);
//���Ѳ���
void HeapPop(HP* php);
//�鿴�Ѷ�Ԫ��
HpDateType HeapTop(HP* php);
//���Ƿ�Ϊ��
bool HeapEmpty(HP* php);
//���ϵ���
void AdjustUP(HpDateType* a,int x);
//���µ���
void AdjustDown(HpDateType* a,int size,int parent);
//����
void Swap(HpDateType* x, HpDateType* y);
//���ش�С
int HeapSize(HP* php);
//�ݻٶ�
void HeapDestroy(HP* php);