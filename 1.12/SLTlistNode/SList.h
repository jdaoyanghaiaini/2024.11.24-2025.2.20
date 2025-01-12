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
//打印结构体
void SLTPrint(SLTNode* phead);
//创建节点
SLTNode* BuySLTNode(SLTDateType x);
//尾插节点
void SLTPushBack(SLTNode** pphead, SLTDateType x);
//头插节点
void SLTPushFront(SLTNode** pphead, SLTDateType x);
//头删节点
void SLTPopFront(SLTNode** pphead);
//尾删节点
void SLTPopBack(SLTNode** pphead);
//查找节点(找到该节点位置返回它的指针)
SLTNode* SLTNodeFind(SLTNode* phead, SLTDateType x);
//插入链表节点的前面
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos);
