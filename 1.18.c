#define _CRT_SECURE_NO_WARNINGS
//int i = 0;
//int* ans = (int*)malloc(numsSize * 2 * sizeof(int));
//for (i = 0; i < numsSize; i++)
//{
//    ans[i] = nums[i];
//    ans[i + numsSize] = nums[i];
//}
//*returnSize = 2 * numsSize;
//return ans;
//ListNode* reserverList(ListNode * rhead)
//{
//    ListNode* p1 = NULL;
//    ListNode* p2 = rhead;
//    ListNode* p3 = NULL;
//
//    while (p2)
//    {
//        p3 = p2->next;
//        p2->next = p1;
//        p1 = p2;
//        p2 = p3;
//
//    }
//    return p1;
//}
//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* head)
//    {
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while (fast && fast->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        ListNode* rhead = reserverList(slow);
//        while (rhead && head)
//        {
//            if (rhead->val != head->val)
//                return false;
//            rhead = rhead->next;
//            head = head->next;
//        }
//        return true;
//    }
//};
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	int t = 0;
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int a, b, c;
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if (a + b + c > a && a + b + c > b && a + b + c > c && a + b > c && a + c > b && b + c > a)
//        {
//
//            if (a == b  a == c && b == c)
//            {
//                if (a == b && c == a)
//                    printf("Equilateral triangle!");
//                else
//                    printf("Isosceles triangle!");
//            }
//            else
//                printf("Ordinary triangle!");
//        }
//        else
//        {
//            printf("Not a triangle!");
//        }
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//#include<stdio.h>
//int main()
//{
//	float i = 0;
//	int j = 0;
//	float sum = 0;
//	for (j = 1; j <= 100; j++)
//	{
//		i = 1;
//		float k =  i / j;
//		if (j % 2 == 0)
//		{
//			sum = sum - k;
//		}
//		else
//			sum = sum + k;
//	}
//	printf("%f ", sum);
//}
//#include<stdio.h>
//int main()
//{
//	int count = 0, i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		int t = i;
//		while (t)
//		{
//			int k = t % 10;
//			t = t / 10;
//			if (k == 9)
//				count++;
//		}
//	}
//	printf("%d", count);
//}
//#include<stdio.h>
//int main()
//{
//	int i = 1000;
//	int count = 0;
//	for (i; i <= 2000; i++)
//	{
//		if (i % 4 == 0 && i % 100 != 0)
//		{
//			printf("%d ", i);
//			count++;
//		}
//		else if (i % 400 == 0)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d", count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int t = 0, k = 0, j = 0;
//	int a = 1, b = 0;
//	scanf("%d %d", &k, &j);
//		if (j > k)
//		{
//			t = j;
//			j = k;
//			k = t;
//		}
//		while (a)
//		{
//			b = k / j;
//			a = k % j;
//			if (a == 0)
//			{
//				printf("%d ", j);
//				return 0;
//			}
//			k = j;
//			j = a;
//		}
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i<10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (int j = 0; j < 9; j++)
//	{
//		
//		if (max < arr[j + 1])
//		max = arr[j + 1];
//		
//	}
//	printf("%d", max);
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
	int j = 1, i = 100, count = 0;
	for (i; i <= 200; i++)
	{
		int flag = 1;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d", count);
	return 0;
}