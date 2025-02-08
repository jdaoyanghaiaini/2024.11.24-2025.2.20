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
//初始化堆
void HeapInit(HP* php);
//入堆操作
void HeapPush(HP* php, HpDateType x);
//出堆操作
void HeapPop(HP* php);
//查看堆顶元素
HpDateType HeapTop(HP* php);
//堆是否为空
bool HeapEmpty(HP* php);
//向上调整
void AdjustUP(HpDateType* a,int x);
//向下调整
void AdjustDown(HpDateType* a,int size,int parent);
//交换
void Swap(HpDateType* x, HpDateType* y);
//返回大小
int HeapSize(HP* php);
//摧毁堆
void HeapDestroy(HP* php);