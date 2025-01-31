//反转链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* p1 = NULL;
//    struct ListNode* p2 = head;
//    struct ListNode* p3 = NULL;//这里不能写p3->next因为节点数可能存在不够的情况；
//    while (p2)
//    {
//        p3 = p2->next;
//        p2->next = p1;
//        p1 = p2;
//        p2 = p3;
//    }
//    return p1;
//}
// 返回中间节点
//struct ListNode* fast = head;
//struct ListNode* slow = head;
//while (fast && fast->next)
//{
//    fast = fast->next->next;
//    slow = slow->next;
//}
//return slow;
//返回第倒数第k个节点
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
//合并两个有序链表
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
//相交链表
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
//    int gap = abs(lenA - lenB);//这个函数表示取绝对值；
//    struct ListNode* shortlist = headA;
//    struct ListNode* longlist = headB;
//    if (lenA > lenB)
//    {
//        longlist = headA;
//        shortlist = headB;
//    }
//    while (gap--)//快慢指针让长的先走差距步，走完后两链表长度相同；
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
//环形链表
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