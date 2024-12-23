#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//结构体
typedef struct Slistnode
{
	int x;
	struct Slistnode* next;
}SLTnode;
//打印
void printf_List(SLTnode** pphead);
//创建
SLTnode* SLTbuynode(int x);
//尾插
void SLTpushback(SLTnode** pphead, int x);
//头插
void SLTpushfront(SLTnode** pphead, int x);
//尾删
void SLTpopback(SLTnode** pphead);
//头删
void SLTpophead(SLTnode** pphead);
//查找
SLTnode* SLTfind(SLTnode* phead, int x);
//在节点前插入
void SLTinsertbefore(SLTnode** pphead, SLTnode* pos, int x);
//在节点后插入
void SLTinsertafter(SLTnode* pos, int x);
//删除某个节点
void SLTErase(SLTnode** pphead, SLTnode* pos);
//删除某个节点之后的节点(一个)
void SLTEraseafter(SLTnode* pos);
//销毁链表
void SLIstdestory(SLTnode** pphead);