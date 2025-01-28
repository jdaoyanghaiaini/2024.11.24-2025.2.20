#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n - i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 1; i <= n - 1; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 1; j <= 2 * n - 2 * i - 1;j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int Num_digit(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n / 10;
//		count++;
//	}
//	return count;
//}
//int Num_power(int n,int num)
//{
//	if (num != 0)
//	{
//		return n * Num_power(n, --num);	
//	}
//	return 1;
//}
//int main()
//{
//	int sum = 0;
//	int count = 0;
//	int total = 0;
//	for (int i = 0; i <= 100000; i++)
//	{
//		if (i == 0)
//		{
//			printf("%d ", i);
//			count++;
//			continue;
//		}
//		total = 0;
//		int num = Num_digit(i);		
//		int k = i;
//		while (k)
//		{
//			int tmp = k % 10;
//			求某数n次方的递归
//			sum = Num_power(tmp,num);
//			total = total + sum;
//			k = k / 10;
//		}
//		if (i == total)
//		{
//			special:
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d ",count);
//}
