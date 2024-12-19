#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>//使用字符函数要使用的头文件
#include<assert.h>//断言函数使用需要包含的头文件assert（条件）条件成立运行，不成立报错；
#include<errno.h>
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
// 3.strcat:用于连接两个字符串;
//       不要自己给自己追加；
// 4.strcmp函数：用于字符串比较大小，单个单个字母的比较，返回0，小于0，大于0的数字
// 5.strncmp
//   strncpy 这三类带有n的字符串函数，它可以规定操作的个数，但同时又有一些差距；
//   strncat
// 
//strncmp它说拷贝几个那么就是几个(这里面不包括\0)而strncat它追加的时候除了加上规定数量的字符还总会在最后加上\0；
// 6.strtok这个函数着重放在下文中讲;     
// 7.strstr函数
//   strstr(1,2)1是目标字符串，2是要找到的目标
//   它可以规定寻找目标，在1中找出并返回对应位置的指针；
// 8.strerror函数： //////使用这两个得包含errno.h
//   c语言运行时会创建一个全局变量error，把报错的编码序号放进去（编码序号它存储的是一个字符串信息）
//   strerror会返回一个指向该字符串的指针，可以打印出报错信息；
// 9.perror函数与strerror差不多把error传进去自动打印报错信息；
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
// 模拟实现strcpy
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
//void Strcpy(char* str1,const char* str)
//{
//	char* start = str1;
//	while (*str1++ = *str++);//这种写法更好，++的优先级要比*高，但对于后置++而言，这里先使用赋值再将地址加1；
//	printf("%s",start);
//}
//int main()
//{
//	char str[20] = "hello world!";
//	char str1[20] = {0};
//	Strcpy(str1, str);
//}
//stract函数的使用
//int main()
//{
//	char str[20] = "hello ";
//	char str1[20] = "world!";
//	strcat(str, str1);
//	printf("%s", str);
//}
//void my_strcat(char* str1, char* str2)
//{
//	char* start = str1;
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	/*while (*str1++ != '\0')复杂复合运算千万别写简单这样写会出错
//	{
//		;
//	}*/
//	while (*str1++ = *str2++)
//		;
//	printf("%s",start);
//}
//int main()
//{
//	char str1[20] = "hello ";
//	char str2[20] = "world!";
//	my_strcat(str1, str2);
//}
//strtok函数的使用
//函数原型strtok(char*1,char*2)返回值是一个字符指针；
//这里的2指针指向的是一个含分隔符的字符串；
//这里的1指向的是一个字符串；
//该函数的作用是清除字符串中的分隔符
//eg:jiangdaoyang@qq.com处理后->>>>>>jiangdaoyangqqcom;
//该函数具有记忆性，可以使用多次，第一次使用是1这里不能是NULL，再次使用时如果1为NULL,那么就会从上一次的位置
//继续向下找，如果找不到对应的分隔符了，返回一个NULL，使用结束；
//int main()
//{
//	char str1[30] = "jiang@.dao.yang";
//	char str2[15] = "@.";
//	char buf[200] = { 0 };
//	char* ret;
//	ret = strcpy(buf, str1);
//	for (ret=strtok(buf,str2);ret!=NULL;ret=strtok(NULL,str2))//返回的指针应该是指向分隔符后第一个字符；
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}
//strstr函数模拟实现；
//const char* My_strstr(const char* str1,const char* str2)
//{
//	const char* cur = str1;
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = str2;
//		while (*s2 &&*s1 &&*s1==*s2)
//		{
//			s1++;
//			s2++;
//			if (*s2 == '\0')
//			{
//				return cur;
//			}
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//		cur++;
//	}
//}
//int main()
//{
//	char str1[20] = "jdyaiaini";
//	char str2[20] = "ain";
//	const char* ret = My_strstr(str1, str2);
//	printf("%s", ret);
//	return 0;
//}
//int main()
//{
//	FILE* pf = fopen("jfkdl", "r");
//	if (pf == NULL);
//	{
//		printf("打开文件失败，原因是：", strerror(errno));
//		perror("打开文件失败，原因是：");
//		fclose(pf);
//		return 0;
//	}
//}







