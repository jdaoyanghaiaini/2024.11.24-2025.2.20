#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>//ʹ���ַ�����Ҫʹ�õ�ͷ�ļ�
#include<assert.h>//���Ժ���ʹ����Ҫ������ͷ�ļ�assert�������������������У�����������
//1.islower�������ж���ĸ�ǲ���Сд��ĸ���ǵĻ�����һ��0���ǵĻ�����һ����0ֵ��
//2.isupper�������Ƿ�Ϊ��д��ĸ������ֵ�߼�������ĺ�����ͬ��
//3.isspace�������ж��Ƿ�Ϊ�հ��ַ������������ո񣩡���"\f","\n",'\r','\t','\v';
//4.tolower��������д����Сд��
//5.toupper������Сдת��д��
//��һ���ַ����е�Сд��ĸ�ĳɴ�д��
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
//�ĳɴ�д
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
//�ַ���������
//1.strlen�����������ַ����ĳ��ȣ�
//2.strcpy��1��2�����ڸ�����������ݵ���һ�������У���2���Ƶ�1�У�
// ������Ҫע��ĵ㣺
//       strcpy�´��\0��������
//       strcpyʹ��ʱҪע��������ڴ����⣻
//       strcpyֻ�Ǹ��ƣ��Ḳ��ԭ�������ݣ������������ӣ�
//ģ��ʵ��strlen��
//void Strlen1(const char* str)//������ʹ�õ���ָ��ȥ����������ϣ��ȥ�ı�����ֵ����const���β��ɸı䣻
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
//strcpy��ʹ��
//int main()
//{
//	char str[20] = "hello world!";
//	char str1[20] = {0};
//	//char str="hello world"���ֶ����ַ��������ķ�����������������Ѿ��ᱨ��������������������з���ͨ����Ҫ֪�����ɱ�����
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














