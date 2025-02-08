#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	HpDateType* tmp = (HpDateType*)malloc(sizeof(HpDateType) * 4);
	assert(tmp);
	php->a = tmp;
	php->size = 0;
	php->capacity = 4;
}
void AdjustUP(HpDateType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)//写出parent>=0有潜在风险，但阴差阳错确实对的
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HpDateType* a,int size,int parent)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* php, HpDateType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HpDateType* tmp = (HpDateType*)realloc(php->a, sizeof(HpDateType) * php->capacity * 2);
		assert(tmp);
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	//进行向上调整
	AdjustUP(php->a, php->size-1);
}
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	//进行向下调整；
	AdjustDown(php->a,php->size,0);
}
bool HeapEmpty(HP* php)
{
	return php->size == 0;
}
HpDateType HeapTop(HP* php)
{
	return php->a[0];
}
int HeapSize(HP* php)
{
	return php->size;
}
void HeapDestroy(HP* php)
{
	free(php->a);
	php->size = 0;
	php->capacity = 0;
}
void Swap(HpDateType* x, HpDateType* y)
{
	HpDateType tmp = *y;
	*y = *x;
	*x = tmp;
}