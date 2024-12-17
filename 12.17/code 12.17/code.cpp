#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>//使用字符函数要使用的头文件
#include<assert.h>//断言函数使用需要包含的头文件assert（条件）条件成立运行，不成立报错；
//1.islower函数：判断字母是不是小写字母不是的话返回一个0，是的话返回一个非0值；
//2.isupper函数：是否为大写字母，返回值逻辑与上面的函数相同；
//3.isspace函数：判断是否为空白字符，包括“（空格）”，"\f","\n",'\r','\t','\v';
//4.tolower函数：大写换成小写；
//5.toupper函数：小写转大写；
//将一个字符串中的小写字母改成大写；
//int main()
//{
//	int i = 0;
//	char str[] = { "I am a student" };
//	while (str[i] != '\0')
//	{
//		i++;
//		if (islower(str[i]) != 0)
//		{
//			str[i] = str[i] - 32;
//		}
//		
//	}
//	printf("%s", str);
//	return 0;
//}
//改成大写
//int main()
//{
//	int i = 0;
//	char str[] = { "I am a student" };
//	while (str[i] != '\0')
//	{
//		i++;
//		if (isupper(str[i]) != 0)
//		{
//			str[i] = str[i] + 32;
//		}
//
//	}
//	printf("%s", str);
//	return 0;
//}
//字符串函数：
//1.strlen函数用于求字符串的长度；
//2.strcpy（1，2）用于复制数组的内容到另一个数组中（将2复制到1中）
// 几个需要注意的点：
//       strcpy会拷贝\0到数组中
//       strcpy使用时要注意数组的内存问题；
//       strcpy只是复制，会覆盖原数组内容，不能做到连接；
//模拟实验strlen；
//void Strlen1(const char* str)//在这里使用的是指针去遍历，但不希望去改变它的值，用const修饰不可改变；
//{
//	assert(str != NULL);
//	int i = 0;
//	int count = 0;
//	while (str[count] != '\0')
//	{
//		count++;
//	}
//	printf("%d", count);
//}
//void Strlen2(const char* str)
//{
//	assert(str != NULL);
//	int i = 0;
//	const char* start = str;
//	while (str[i] != '\0')
//	{
//		i++;
//		start++;
//	}
//	printf("%d", start - str);
//}
//int Strlen3(char* str)
//{
//	assert(str != NULL);
//	if (*str!='\0')
//	{
//		return 1 + Strlen3(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//	char str[] = { "abcdef" };
//	Strlen1(str);
//	Strlen2(str);
//	int c = Strlen3(str);
//	printf("%d", c);
//	return 0;
//}
//strcpy的使用
//int main()
//{
//	char str[20] = "hello world!";
//	char str1[20] = {0};
//	//char str="hello world"这种定义字符串常量的方法在这个编译器内已经会报错，但如果在其它编译器中发现通过，要知道不可被复制
//	strcpy(str1, str);
//	printf("%s", str1);
//}
//
//void Strcpy(char* str1, char* str)
//{
//	int i = 0;
//	for (i = 0; str1[i] != '\0'; i++)
//	{
//		str[i] = str1[i];
//	}
//	printf("%s", str);
//}
//int main()
//{
//	char str[20] = "hello world!";
//	char str1[20] = {0};
//	Strcpy(str1, str);
//}














