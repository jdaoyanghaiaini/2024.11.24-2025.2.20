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
//初始化
void QueueInit(Queue* pq);
//删除队列
void QueueDestroy(Queue* pq);
//插入数据
void QueuePush(Queue* pq, QDateType x);
//删除数据
void QueuePop(Queue* pq);
//统计大小
int QueueSize(Queue* pq);
//判断是否为空
bool QueueEmpty(Queue* pq);
//队首数据的显示
QDateType QueueFront(Queue* pq);
//队尾数据显示
QDateType QueueBack(Queue* pq);

