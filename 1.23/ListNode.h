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
//销毁链表
void LTDestroy(LTNode* phead);
//实现初始化
LTNode* LTInit();
//创建节点
LTNode* LTBuyNode(LTDateType x);
//尾删
void LTPopBack(LTNode* phead);
//尾插节点
void LTPushBack(LTNode* phead, LTDateType x);
//打印链表
void LTPrint(LTNode* phead);
//头插
void LTPushFront(LTNode* phead,int x);
//头删
void LTPopFront(LTNode* phead);
//判断链表是否为空
bool LTEmpty(plist);
//查找节点
LTNode* LTFind(LTNode* phead, LTDateType x);
//某位置之前插入节点
void LTInsert(LTNode* pos, LTDateType x);
//删除某节点
void LTErase(LTNode* pos);