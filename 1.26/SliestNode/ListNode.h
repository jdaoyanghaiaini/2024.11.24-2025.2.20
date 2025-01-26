#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef struct ListNode LTNode;
typedef int LTDateType;
struct ListNode
{
	LTDateType date;
	LTNode* next;
	LTNode* prev;	
};
//创造节点
LTNode* LTBuyNode(LTDateType x);
//初始化节点
LTNode* LTInit();
//打印节点
void LTPrint(LTNode* phead);
//头插
void LTPushFront(LTNode* phead,LTDateType x);
//头删
void LTPopFront(LTNode* phead);
//判断链表是否为空
bool LTEmpty(LTNode* phead);
//尾插
void LTPushBack(LTNode* phead, LTDateType x);
//尾删
void LTPopBack(LTNode* phead);
//找到某节点
LTNode* LTFind(LTNode* phead, LTDateType x);
//任意位置之前插入
void LTInsert(LTNode* pos, LTDateType x);
//删除任意位置
void LTErase(LTNode* pos);
//销毁链表
void LTDestroy(LTNode* phead);
