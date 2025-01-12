#include"SList.h"
SLTNode* test = NULL;
void Test1()
{
	SLTPushBack(&test, 1);
	SLTPrint(test);

	SLTPushBack(&test, 2);
	SLTPrint(test);

	SLTPushBack(&test, 3);
	SLTPrint(test);

	SLTPushFront(&test, 0);
	SLTPrint(test);

	SLTPushFront(&test, -1);
	SLTPrint(test);

	SLTPushFront(&test, -2);
	SLTPrint(test);

	SLTPopFront(&test);
	SLTPrint(test);

	SLTPopBack(&test);
	SLTPrint(test);

	SLTNode* find = SLTNodeFind(test,-1);
	SLTPrint(test);
	SLTInsert(&test, find, -2);
	SLTPrint(test);

	SLTNode* find2 = SLTNodeFind(test, 0);
	SLTErase(&test, find2);
	SLTPrint(test);


}
int main()
{
	Test1();
}