#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int QDateType;
typedef struct QueueNode {
	struct QueueNode* next;
	QDateType date;
}QNode;
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;
//��ʼ��
void QueueInit(Queue* pq);
//ɾ������
void QueueDestroy(Queue* pq);
//��������
void QueuePush(Queue* pq, QDateType x);
//ɾ������
void QueuePop(Queue* pq);
//ͳ�ƴ�С
int QueueSize(Queue* pq);
//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//�������ݵ���ʾ
QDateType QueueFront(Queue* pq);
//��β������ʾ
QDateType QueueBack(Queue* pq);

