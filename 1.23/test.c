#include"ListNode.h"
void Test1()
{
	int y = 7;
	LTNode* plist = LTInit();
	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTPushFront(plist, 0);
	LTPushFront(plist, -1);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTInsert(LTFind(plist, 0), -1);
	LTPrint(plist);

	LTErase(LTFind(plist, -1));
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}
int main()
{
	Test1();
}