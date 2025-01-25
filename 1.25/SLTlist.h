#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct SLTlistNode SLTNode;//对结构体重新命名，方便下文使用；
typedef int SLTDateType;
//这里将int命名是为了方便以后更改存储数据的类型
//比如要储存浮点型在这里将int改为float就行了；
struct SLTlistNode {
	SLTNode* next;//指针域保留下个节点的地址
	SLTDateType date;//数据域存储数据；
};
//打印链表
void SLTPrint(SLTNode* phead);
//头删
void SLTPopFront(SLTNode** pphead);
//头插
void SLTPushFront(SLTNode** pphead, SLTDateType x);
//创建节点
SLTNode* SLTBuyNode(SLTDateType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//尾插
void SLTPushBack(SLTNode** pphead, SLTDateType x);
//在任意一个节点前插入新节点
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//删除任意位置的节点
void SLTErase(SLTNode** pphead, SLTNode* pos);
//找到某位置
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);
//销毁链表
void SLTDestroy(SLTNode** pphead);