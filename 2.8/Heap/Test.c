#include"Heap.h"
int main()
{
	HP php;
	HeapInit(&php);
	HeapPush(&php, 15);
	HeapPush(&php, 6);
	HeapPush(&php, 18);
	HeapPush(&php, 20);
	HeapPush(&php, 45);
	HeapPush(&php, 17);
	while (!HeapEmpty(&php))
	{
		printf("%d ", HeapTop(&php));
		HeapPop(&php);
	}
	HeapDestroy(&php);
	return 0;
}