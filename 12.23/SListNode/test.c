#include"lianb.h"
int main()
{
	SLTnode* head = NULL;
	SLTpushback(&head, 1);
	SLTpushback(&head, 2);
	SLTpushback(&head, 3);
	SLTpushback(&head, 4);
	SLTpushback(&head, 5);
	SLTnode* find=SLTfind(head, 3);
	SLTinsertbefore(&head,find,10);
	SLTinsertafter(find,11);
	printf_List(&head);
	SLTnode* find1 = SLTfind(head, 3);
	SLTErase(&head, find1);
	printf_List(&head);
	//删除某个节点之后的节点
    find = SLTfind(head, 10);
	SLTEraseafter(find);
	printf_List(&head);
	return 0;
}