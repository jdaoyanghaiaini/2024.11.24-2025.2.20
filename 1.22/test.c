#include"ListNode.h"
void Test1()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 1);
	LTPushFront(plist, 2);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);
}
int main()
{
	Test1();
}