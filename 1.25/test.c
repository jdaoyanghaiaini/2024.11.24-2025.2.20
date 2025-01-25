#include"SLTlist.h"
void Test1()
{
	//�����������������ǽ��г�ʼ����
	SLTNode first = { NULL,1 };
	SLTNode second = { NULL,2 };
	SLTNode third = { NULL,3 };
	SLTNode forth = { NULL,4 };
	first.next = &second;
	//��һ���ڵ��nextָ��洢����һ���ڵ�ĵ�ַ
	second.next = &third;
	third.next = &forth;
	forth.next = NULL;
	SLTPrint(&first);
}
void Test2()
{
	SLTNode* head = NULL;
	SLTPushFront(&head,1);
	SLTPushFront(&head, 2);
	SLTPushFront(&head, 3);
	SLTPushFront(&head, 4);
	SLTPrint(head);

	SLTPopFront(&head);
	SLTPrint(head);

	SLTPushBack(&head, 2);
	SLTPrint(head);

	SLTPushBack(&head, 3);
	SLTPushBack(&head, 4);
	SLTPushBack(&head, 5);
	SLTPrint(head);

	SLTPopBack(&head);
	SLTPrint(head);

	SLTInsert(&head, SLTFind(head, 1), 0);
	SLTPrint(head);

	SLTErase(&head, SLTFind(head, 3));
	SLTPrint(head);
	
	SLTDestroy(&head);
	SLTPrint(head);

}
int main()
{
	/*Test1();*/
	Test2();
}