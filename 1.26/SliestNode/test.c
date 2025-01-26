#include"ListNode.h"
void Test1()
{
	LTNode * head = LTInit();
	LTPushFront(head, 1);
	LTPushFront(head, 2);
	LTPushFront(head, 3);
	LTPushFront(head, 4);
	LTPrint(head);
	
	LTPopFront(head);
	LTPrint(head);

	LTPushBack(head, 2);
	LTPrint(head);


	LTPopBack(head);
	LTPrint(head);

	LTInsert(LTFind(head, 2), 3);
	LTPrint(head);


	LTInsert(LTFind(head, 3), 3);
	LTPrint(head);

	LTErase(LTFind(head, 2));
	LTPrint(head);

}
int main()
{
	Test1();
}