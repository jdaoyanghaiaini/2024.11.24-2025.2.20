#define _CRT_SECURE_NO_WARNINGS
//�ڴ溯����ʹ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char str1[30] = "jiangdaoy";
//	char str2[20] = "ang";
//	memcpy(str1 + 9, str2, 3);//memcpy�����ڴ渴�ƣ���str2�е����ݸ��Ƶ�str1+9���λ���Ժ�ע�����������ܸ����ظ��Ŀռ�
//	memmove(str1 + 9, str2, 3)��memmove�������������memcpy���ò�࣬�������Ը����ظ��Ŀռ䣻
//	memset(str1, 'a', 4);����������Խ�str1��ָ�����ĸ��ֽڿռ��Ϊa��
//	memcmp(str1 + 2, str2, 3);����������ԱȽ�ָ���Ŀռ䣻
//}
//ʵ��memmove
//void* My_memmove(void* dest, void* src,int num)
//{
//	void* start = dest;
//	if (dest < src)
//	{
//		while(num--)
//		{
//			*(char*)dest =*(char*)src ;
//			//(char*)dest++����д���ǲ��еģ�ǿ��ת������һ˲ǿת����ʹ�õĻ�ûת��
//			*(char*)dest = *(char*)dest + 1;
//			*(char*)src = *(char*)src + 1;
//		}
//		return start;
//
//	}
//	else
//	{
//		while(num--)
//		{
//			*((char*)dest+num) = *((char*)src+num);
//		}
//		return start;
//	}
//	
//}
//int main()
//{
//	char str1[30] = "jiangdaoyang";
//	char str2[20] = "haiaini";
//	char* ret=(char*)My_memmove(str1, str1+4,7);
//	printf("%s", ret);
//	return 0;
//}