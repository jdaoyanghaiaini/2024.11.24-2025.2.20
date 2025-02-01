#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct stack ST;
typedef int STDateType;
struct  stack {
	STDateType* a;
	int capacity;
	int top;
};
//初始化栈
void STInit(ST* ps);
//销毁栈
void STDestroy(ST* ps);
//插入数据
void STPush(ST* ps,STDateType x);
//删除数据
void STPop(ST* ps);
//栈是否为空
bool STEmpty(ST* ps);
//栈的大小
void STSize(ST* ps);