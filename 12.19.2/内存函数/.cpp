#define _CRT_SECURE_NO_WARNINGS
//内存函数的使用
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char str1[30] = "jiangdaoy";
//	char str2[20] = "ang";
//	memcpy(str1 + 9, str2, 3);//memcpy用于内存复制，将str2中的内容复制到str1+9这个位置以后；注意的是这个不能复制重复的空间
//	memmove(str1 + 9, str2, 3)；memmove函数这个函数与memcpy作用差不多，但他可以复制重复的空间；
//	memset(str1, 'a', 4);这个函数可以将str1中指定的四个字节空间变为a；
//	memcmp(str1 + 2, str2, 3);这个函数可以比较指定的空间；
//}
//实现memmove
//void* My_memmove(void* dest, void* src,int num)
//{
//	void* start = dest;
//	if (dest < src)
//	{
//		while(num--)
//		{
//			*(char*)dest =*(char*)src ;
//			//(char*)dest++这种写法是不行的，强制转换在那一瞬强转，在使用的话没转；
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