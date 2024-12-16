#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//void Bubblesort(int* arr, int* sz) {
//    int i, j, temp;
//    int flag;
//    for (i = 0; i < *sz - 1; i++) {
//        flag = 0;
//        for (j = 0; j < *sz - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//                flag = 1;
//            }
//        }
//        if (flag == 0)
//            break;
//    }
//}
//
//void Output(int* arr, int* sz) {
//    int i;
//    for (i = 0; i < *sz; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() 
//{
//    int num = 0;
//    int* *arr = NULL;
//    int sz = 0;
//    int* Sz = &sz;
//    printf("输入在数组中的元素，输入非数字结束：\n");
//    arr = (int**)malloc(sizeof(int*));
//    *arr = (int*)malloc(sizeof(int));
//    while (1) {
//        int judge = scanf("%d", &num);
//        if (judge != 1) {
//            break;
//        }
//        *arr = (int*)realloc(*arr, (sz + 1) * sizeof(int));
//        (*arr)[sz++] = num;
//    }
//    printf("请输入要插入的数据,输入非数字表示结束：\n");
//    while (1) {
//        while (getchar() != '\n');
//        int judge2 = scanf("%d", &num);
//        if (judge2 != 1) {
//            break;
//        }
//        *arr = (int*)realloc(*arr, (sz + 1) * sizeof(int));
//        (*arr)[sz++] = num;
//    }
//    Bubblesort(*arr, Sz);
//    Output(*arr, Sz);
//    free(*arr);
//    free(arr);
//    return 0;
//
//scanf函数的读取内容取决于它的格式控制符，如当格式控制符未%d，%s，%f时，此时的scanf会遇到如空格，制表符，时会停止读取
//但当格式控制符为%c，此时会读取空格；
//#include<stdio.h>
/*/int main()
{
	char str[100];
	scanf("%s", &str);
	printf("%s", str);
	return 0;
}*/


//#include<stdio.h>
//void Max(int* n, int* k, int* c)
//{
//	int max = (*c) > ((*n) > (*k) ? (*n) : (*k)) ? (*c) : (*n) > (*k) ? (*n) : (*k);
//	printf("%d", max);
//}
//int main()
//{
//	int n = 0, k = 0, c = 0;
//	printf("请输入三个数字，用空格分开");
//	scanf("%d %d %d", &n, &k, &c);
//	Max(&n, &k, &c);
//	return 0;
////}
//#include<stdio.h>
//#include<stdlib.h>
//struct Stu
//{
//	char name[20];
//	int number[20];
//	float grade1;
//	float grade2;
//	float grade3;
//};
//void Average_grade(struct Stu*stus,int n,float *score)
//{
//	int allgrade1 = 0;
//	int allgrade2 = 0;
//	int allgrade3 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		allgrade1+=(stus[i].grade1);
//		allgrade2 += (stus[i].grade2);
//		allgrade3 += (stus[i].grade3);
//	}
//		printf("第1门的平均成绩是：%d",allgrade1/n);
//		printf("第2门的平均成绩是：%d", allgrade2 / n);
//		printf("第3门的平均成绩是：%d", allgrade3/ n);
//}
//int main()
//{
//	struct Stu* stus;
//	int n = 0,i = 0;
//	printf("请输入要输入学生的个数：");
//	scanf("%d", &n);
//	stus = (struct Stu*)malloc(n*sizeof(*stus));
//	if (stus == NULL)
//	{
//		printf("内存分配失败");
//		return 0;
//	}
//	for (i; i < n; i++)
//	{
//	  printf("输入第%d个学生的姓名:\n", i+1);
//	  scanf("%s",&stus[i].name);
//	  printf("输入第%d个学生的学号:\n", i+1);
//	  scanf("%d",&stus[i].number);
//	  printf("输入第%d个学生的第1门成绩：\n", i+1);
//	  scanf("%f",&stus[i].grade1);
//	  printf("输入第%d个学生的第2门成绩：\n", i+1);
//	  scanf("%f",&stus[i].grade2);
//	  printf("输入第%d个学生的第3门成绩：\n", i+1);
//	  scanf("%f",&stus[i].grade3);
//	}
//	float score[2];
//	Average_grade(stus, n, score);
//	free(stus);
//	return 0;
//}
//#include<stdio.h>
//void Bubblesort(char** name)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3 - i; j++)
//		{
//			if (*name[j] > *name[j + 1])
//			{
//				int t = 0;
//				t = *name[j + 1];
//				*name[j + 1] = *name[j];
//				*name[j] = t;
//			}
//		}
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%s ", name[i]);
//
//	}
//}
//int main()
//{
//	char str1[10] = "Fellow";
//	char str2[10] = "Great";
//	char str3[10] = "Fortran";
//	char str4[10] = "Computer";
//	char* name[4] ={str1,str2,str3,str4};
//	Bubblesort(name);
//	printf("%s", *name[1]);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct Exa{
//	char name[15];
//	struct Exa* next;
//};
//void Print(struct Exa* head)
//{
//	struct Exa* p = head;
//	while (p!= NULL)
//	{
//		printf("%s ", p->name);
//		p = p->next;
//	}
//}
//struct Exa* Create(struct Exa* head)
//{
//	struct Exa* New;
//	printf("输入单个数字表示退出创建：\n");
//	while (1)
//	{
//		printf("输入你要输入的姓名\n");
//		New = (struct Exa*)malloc(sizeof(struct Exa));
//		New->next = NULL;
//		scanf("%s", &(New->name));
//		int i = strcmp(New->name, "over");
//		if (i==0)
//		{
//			return head;
//		}
//		if (head == NULL)
//		{
//			head = New;
//		}
//		else
//		{
//			New->next = head;
//			head = New;
//		}
//	}
//}
//int main()
//{
//	struct Exa* head = NULL;
//	head = Create(head);
//	Print(head);
//}

//？？？？？？？？？？？？？？？？？？？？为什么溢出
//#include <stdio.h>
//#include<string.h>
//int main()
//{
//    int i = 0;
//    char str[100];
//    char* p2 = str;
//    char* p1 = str;
//    fgets(str, 100, stdin);
//    while ((*p2) != '\0')
//    {
//        p2++;
//        i++;
//    }
//    int j = 0;
//    for (j = 0; j < i / 2; j++)
//    {
//        char t = 0;
//        t = *(p1 + j);
//        *(p1 + j) = *(p2 - j-1);
//        *(p2 - j-1) = t;
//    }
//    printf("%s", str);
//    return 0;
//}
//}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0, j = 0;
//	int k = 0;
//	char str1[20] = { 0 };
//	char str2[20] = { 0 };
//	for (i = 0; i < 20; i++)
//	{
//		if ((scanf("%c", &str1[i]))!=1)
//		{
//			break;
//		}
//	
//	}
//	printf("输入要左旋的位数：");
//	scanf("%d", &k);
//	for (i = 0; i < k; i++)
//	{
//		str2[i] = str1[i];
//	}
//	for (i = 0; i < k; i++)
//	{
//		str1[i] = str1[i + k];
//	}
//	for (i = 0; i < k; i++)
//	{
//		str1[i + k] = str2[i];
//	}
//	printf("%s\n", str1);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0, j = 0;
//	char str1[20];
//    
//	return 0;
//}
//
//#include<stdio.h>
//#include<string.h>
//void Swap(char *str)
//{
//	int len = strlen(str);
//	char* left = str;
//	char* right=str+len-1;
//	while (left < right)
//	{
//		char t = 0;
//		t = *right;
//		*right = *left;
//		*left = t;
//		*right--;
//		*left++;
//	}
//}
//int main()
//{
//	char str1[20] = { 0 };
//	fgets(str1, 20, stdin);
//	if (str1[strlen(str1+1)] == '\n')
//	{
//		str1[strlen(str1+1)] = '\0';
//	}
//	Swap(str1);
//	printf("%s", str1);
//	return 0;
//}
//左旋字符
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int i = 0, j = 0, k = 0;
//	char str[100] = { 0 };
//	printf("输入一串字符串\n");
//
//	fgets(str, 100, stdin);
//	if (str[strlen(str) - 1] == '\n')
//	{
//		str[strlen(str) - 1] = '\0';
//	}
//	int len = strlen(str);
//	printf("输入左旋次数：\n");
//	scanf("%d", &k);
//	int time = k%len;
//	for (i = 0; i < time; i++)
//	{
//		char t = str[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			str[j] = str[j + 1];
//			if (j == len - 2)
//			{
//				str[j + 1] = t;
//			}
//		}
//	}
//	printf("%s", str);
//	return 0;
//}
//模拟strlen
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	int count = 0;
//	int i = 0;
//	char str1[300];
//	printf("输入一串字符串:");
//	fgets(str1, 300, stdin);
//	while (str1[i]!='\0')
//	{
//		count++;
//		i++;
//	}
//	printf("%d\n", strlen(str1));
//	printf("%d", count);
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int compare(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//int main()
//{
//	int arr[10] = { 8,56,1,45,61,31,854 };
//	qsort(arr, 7, 4, compare);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}
//struct Stu {
//	char name[20];
//	int year;
//}stu1 = { "zhangsan",18 },
//stu2 ={"lisi", 20};
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int compare(const void* p1,const void* p2)
//{
//	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
//}
//int main()
//{
//	struct Stu stu3 = { "xiaoming",21 };
//	struct Stu arr[] = { stu1,stu2,stu3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(struct Stu), compare);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%8s %d\n", arr[i].name,arr[i].year);
//	}
//}
//qsort实现
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu{
	char name[20];
	int old = 0;
};
void Swap(char* buf1,char* buf2,int width)
{
	int i = 0;
	char tmp = 0;
	for (i = 0; i < width; i++)
	{
		tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void Bubblesort(void* base,int num,int width,int (*compare)(const void* p1,const void* p2))
{
	int i = 0, j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (compare((char*)base+j*width,(char*)base+(j+1)*width)>0)
			{
				Swap((char*)base + j * width,(char*)base + (j + 1) * width,width);
			}
		}
	}
}
int comp_stu(const void* p1,const void* p2)
{
	return strcmp(((Stu*)p1)->name, ((Stu*)p2)->name);
}
int comp_num(const void* p1, const void* p2)
{
	return *((int*)p1) - *((int*)p2);
}
int main()
{
	int k = 0;
	struct Stu stu1 = { "zhangsan",18 };
	struct Stu stu2 = { "lisi",21 };
	struct Stu stu3 = { "xiaoming",25 };
	Stu arr[] = { stu1,stu2,stu3 };
	int arr1[] = {7,84,5,154,51,45,84,15,};
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	int sz2 = sizeof(arr1) / sizeof(arr1[0]);
	Bubblesort(arr,sz1,sizeof(struct Stu),comp_stu);
	Bubblesort(arr1, sz2, sizeof(int), comp_num);
	for (k = 0; k < sz2; k++)
	{
		printf("%d ", arr1[k]);
	}
	printf("\n");
	for (k = 0; k < sz1; k++)
	{
		printf("%d %s\n", arr[k].old, arr[k].name);
	}
	return 0;
}












