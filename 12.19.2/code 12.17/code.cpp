#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>//ʹ���ַ�����Ҫʹ�õ�ͷ�ļ�
#include<assert.h>//���Ժ���ʹ����Ҫ������ͷ�ļ�assert�������������������У�����������
#include<errno.h>
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
// 3.strcat:�������������ַ���;
//       ��Ҫ�Լ����Լ�׷�ӣ�
// 4.strcmp�����������ַ����Ƚϴ�С������������ĸ�ıȽϣ�����0��С��0������0������
// 5.strncmp
//   strncpy ���������n���ַ��������������Թ涨�����ĸ�������ͬʱ����һЩ��ࣻ
//   strncat
// 
//strncmp��˵����������ô���Ǽ���(�����治����\0)��strncat��׷�ӵ�ʱ����˼��Ϲ涨�������ַ����ܻ���������\0��
// 6.strtok����������ط��������н�;     
// 7.strstr����
//   strstr(1,2)1��Ŀ���ַ�����2��Ҫ�ҵ���Ŀ��
//   �����Թ涨Ѱ��Ŀ�꣬��1���ҳ������ض�Ӧλ�õ�ָ�룻
// 8.strerror������ //////ʹ���������ð���errno.h
//   c��������ʱ�ᴴ��һ��ȫ�ֱ���error���ѱ���ı�����ŷŽ�ȥ������������洢����һ���ַ�����Ϣ��
//   strerror�᷵��һ��ָ����ַ�����ָ�룬���Դ�ӡ��������Ϣ��
// 9.perror������strerror����error����ȥ�Զ���ӡ������Ϣ��
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
// ģ��ʵ��strcpy
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
//	while (*str1++ = *str++);//����д�����ã�++�����ȼ�Ҫ��*�ߣ������ں���++���ԣ�������ʹ�ø�ֵ�ٽ���ַ��1��
//	printf("%s",start);
//}
//int main()
//{
//	char str[20] = "hello world!";
//	char str1[20] = {0};
//	Strcpy(str1, str);
//}
//stract������ʹ��
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
//	/*while (*str1++ != '\0')���Ӹ�������ǧ���д������д�����
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
//strtok������ʹ��
//����ԭ��strtok(char*1,char*2)����ֵ��һ���ַ�ָ�룻
//�����2ָ��ָ�����һ�����ָ������ַ�����
//�����1ָ�����һ���ַ�����
//�ú���������������ַ����еķָ���
//eg:jiangdaoyang@qq.com�����->>>>>>jiangdaoyangqqcom;
//�ú������м����ԣ�����ʹ�ö�Σ���һ��ʹ����1���ﲻ����NULL���ٴ�ʹ��ʱ���1ΪNULL,��ô�ͻ����һ�ε�λ��
//���������ң�����Ҳ�����Ӧ�ķָ����ˣ�����һ��NULL��ʹ�ý�����
//int main()
//{
//	char str1[30] = "jiang@.dao.yang";
//	char str2[15] = "@.";
//	char buf[200] = { 0 };
//	char* ret;
//	ret = strcpy(buf, str1);
//	for (ret=strtok(buf,str2);ret!=NULL;ret=strtok(NULL,str2))//���ص�ָ��Ӧ����ָ��ָ������һ���ַ���
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}
//strstr����ģ��ʵ�֣�
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
//		printf("���ļ�ʧ�ܣ�ԭ���ǣ�", strerror(errno));
//		perror("���ļ�ʧ�ܣ�ԭ���ǣ�");
//		fclose(pf);
//		return 0;
//	}
//}







