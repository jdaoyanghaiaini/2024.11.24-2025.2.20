#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
////��С���жϣ�
//int main()
//{
//	int n = 12345678;
//		if (*(char*)&n==78)
//	    {
//		printf("С��");
//	    }
//	else
//		printf("���");
//	return 0;
//}
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// �ṹ��(���������ڴ����)
// 1.��������Ľṹ:enum,union��
//struct STU {
//	char a; //1  8 1
//	char name[10];// 1 8 1
//	int y;// 4 8 4
//};
//int main()
//{
//	pritnf("%d", sizeof(struct STU));
//	return 0;
//}
// �ṹ���ڴ���㷽��
// 1.��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ��(�˻�������ʱ���뽫��һ����Ա���ڵ�ַΪ0���ڴ洦)
// 2.������Ա����Ҫ���䵽ĳ�������������ĵ�ַ��
//   ������=������Ĭ�ϵ�һ����������ó�Ա��С�Ľ�Сֵ��
//   vs��Ĭ�϶�������8
// 3.�ṹ���ܴ�СΪ����������ÿ����Ա�����Ķ�����������������
// 4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ����������������������ṹ��������������ṹ��
// �������С��������������������Ƕ�ף�����������
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// ��̬�ڴ����
// 1.void* malloc(size_t);����һ�������ռ��С�Ŀ�ָ��
// 2.void* relloc(*p,size_t);��Ŀ��ռ���ָ���Ŀռ��С
// 3.void* calloc(size_t num, size_t size)������ĳ�����͵Ŀռ���ٸ���
// ʹ��ע��:
// ���ܻῪ��ʧ�ܣ����Բ�Ҫֱ����ԭָ����գ�����ԭ��������Ҳ��ʧ�ˣ�
// 
//�������
// ��̬�ڴ��������Ŀ
// 1.
//void GetMemory(char* p)һ��ָ����������ָ��������
//{
//	p = (char*)malloc(100);//���ٿռ䣬�������涼����ʱ�Ŀ�����û�ж�str���в�����
//}//////////////////////////�����������ڶ��������Ŀռ䣬�˳��������������Ŀռ䲻�����٣�
//                           ��������Ҳ�Ҳ�������ռ䣬���Ǿͻᵼ���ڴ�й©��
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);//���ﴫ����ָ�����������ָ��ĵ�ַ�����������Ǵ�ֵ����
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
// 
// 
//2. 
//char* GetMemory()
//{
//	char p[] = "hello world";//ע�������ﴴ���ַ��������˼����ջ��������ռ�
//	return p;                //��ζ���˳�����������������������ڽ�������ʱ���ڴ滹������ϵͳ
 //}                         �޷����ʣ�
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//����дһ�δ������������Ƚ�
//int* Test()
//{
//    int a = 9;
//    return &a;����Ҳ��һ����ջ��������Ŀռ䣬�˳�������
//}
//int main()
//{
//    int* n = Test();
//    //printf("hehe");
//    printf("%d", *n);
//}
//���ﻹ��һ���Ա�
//int Test()
//{
//    int a = 9;
//    return a;�����ַ���ֵ�ǻ��ȷ��ڼĴ����Ϸ��ظ������������Բ������٣�
//}
//int main()
//{
//    int n = Test();
//    printf("hehe\n");
//    printf("%d", n);
//}
// 3.��δ���ըһ��û�����⣬������м��ڶ��Ϸ����˿ռ�һ�㶼��ζ����Ҫ�����Լ�free�ͷţ�
//void Getmemory(char** p,int num)���洫����ָ���ַ����ô�����ö���ָ����գ�
//{
//	*p = (char*)malloc(num);
//}
//void Test()                      /////*str--------------------->**p
//{                                /////str---------------------->*p
//	char* str = NULL;              /////&str--------------------->p
//	Getmemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
// 4.
//void Test()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//  free(str);//����֮����޷�ʹ����
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//�������飺�ṹ�������һ���������Ŀռ���Բ��̶�;
//struct STU {
//	int x;
//	int arr[];//��һ��д��
//};
//struct STU1 {
//	int x;
//	int arr[0];//�ڶ���д��
//};
//int main()
//{
//	printf("%d", sizeof(struct STU));//����д��������Ľ��Ϊ4����ζ�Ŵ�ʱ�ṹ���ʱ������������С
//	return 0;
//}
//int main()
//{
//	struct STU* s1;
//	struct STU* tmp = (struct STU*)malloc(sizeof(struct STU) + 40);���������ʹ��
//	assert(tmp);
//	s1 = tmp;
//	for (int i = 0; i < 10; i++)
//	{
//		s1->arr[i] = i + 1;
//		printf("%d ", (s1->arr)[i]);
//	}
//	return 0;
//}

//�ڴ��пռ�Ļ���
//
//             ջ��������������
//             ���ֲ������ȣ�
//   
//               �ڴ�ӳ���
// 
//         
//             ����(��������)
//   ��malloc,realloc,calloc����Ŀռ䣩
// 
// 
//  ��̬����ֻ��������static���εľ�̬������
//
//
//


