//��ת����
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* p1 = NULL;
//    struct ListNode* p2 = head;
//    struct ListNode* p3 = NULL;//���ﲻ��дp3->next��Ϊ�ڵ������ܴ��ڲ����������
//    while (p2)
//    {
//        p3 = p2->next;
//        p2->next = p1;
//        p1 = p2;
//        p2 = p3;
//    }
//    return p1;
//}
// �����м�ڵ�
//struct ListNode* fast = head;
//struct ListNode* slow = head;
//while (fast && fast->next)
//{
//    fast = fast->next->next;
//    slow = slow->next;
//}
//return slow;
//���صڵ�����k���ڵ�
//struct ListNode* fast = head;
//struct ListNode* slow = head;
//k = k - 1;
//while (k--)
//{
//    fast = fast->next;
//}
//while (fast->next)
//{
//    slow = slow->next;
//    fast = fast->next;
//}
//return slow->val;
//�ϲ�������������
//struct ListNode* src1 = list1;
//struct ListNode* src2 = list2;
//struct ListNode* tail = NULL;
//struct ListNode* head = NULL;
//if (src1 == NULL)
//return list2;
//if (src2 == NULL)
//return list1;
//while (src1 && src2)
//{
//    if (src1->val < src2->val)
//    {
//        if (head == NULL)
//        {
//            head = tail = src1;
//        }
//        else
//        {
//            tail->next = src1;
//            tail = src1;
//        }
//        src1 = src1->next;
//    }
//    else
//    {
//        if (head == NULL)
//        {
//            head = tail = src2;
//        }
//        else
//        {
//            tail->next = src2;
//            tail = src2;
//        }
//        src2 = src2->next;
//    }
//}
//if (src1 == NULL)
//tail->next = src2;
//if (src2 == NULL)
//tail->next = src1;
//return head;
//�ཻ����
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    int lenA = 1, lenB = 1;
//    struct ListNode* tailA = headA;
//    struct ListNode* tailB = headB;
//    while (tailA->next)
//    {
//        tailA = tailA->next;
//        lenA++;
//    }
//    while (tailB->next)
//    {
//        tailB = tailB->next;
//        lenB++;
//    }
//    if (tailA != tailB)
//        return NULL;
//    int gap = abs(lenA - lenB);//���������ʾȡ����ֵ��
//    struct ListNode* shortlist = headA;
//    struct ListNode* longlist = headB;
//    if (lenA > lenB)
//    {
//        longlist = headA;
//        shortlist = headB;
//    }
//    while (gap--)//����ָ���ó������߲�ಽ�����������������ͬ��
//    {
//        longlist = longlist->next;
//    }
//    while (longlist != shortlist)
//    {
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return longlist;
//}
//��������
//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//            return true;
//    }
//    return false;
//
//}
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tailA, * tailB;
//    tailA = headA;
//    tailB = headB;
//    int lenA = 1, lenB = 1;
//    while (tailA->next)
//    {
//        tailA = tailA->next;
//        lenA++;
//    }
//    while (tailB->next)
//    {
//        tailB = tailB->next;
//        lenB++;
//    }
//    int gap = abs(lenA - lenB);
//    struct ListNode* longlist = headA;
//    struct ListNode* shortlist = headB;
//    if (lenA < lenB)
//    {
//        longlist = headB;
//        shortlist = headA;
//    }
//    while (gap--)
//    {
//        longlist = longlist->next;
//    }
//    while (longlist != shortlist)
//    {
//        longlist = longlist->next;
//        shortlist = shortlist->next;
//    }
//    return longlist;
//}