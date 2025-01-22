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
//实现初始化
LTNode* LTInit();
//删除链表
void LTDestroy();
//创建节点
LTNode* LTBuyNode(LTDateType x);
//尾删

//尾插节点
void LTPushBack(LTNode* phead, LTDateType x);
//打印链表
void LTPrint(LTNode* phead);
//头插
void LTPushFront(LTNode* phead,int x);
//头删
void LTPopFront(LTNode* phead);