#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
////大小端判断；
//int main()
//{
//	int n = 12345678;
//		if (*(char*)&n==78)
//	    {
//		printf("小端");
//	    }
//	else
//		printf("大端");
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
// 结构体(着重掌握内存对齐)
// 1.两种特殊的结构:enum,union；
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
// 结构体内存计算方法
// 1.第一个成员在与结构体变量偏移量为0的地址处(人话：计算时假想将第一个成员放在地址为0的内存处)
// 2.其他成员变量要对其到某个数字整数倍的地址处
//   对其数=编译器默认的一个对其数与该成员大小的较小值；
//   vs中默认对其数是8
// 3.结构体总大小为最大对其数（每个成员变量的对其数）的整数倍；
// 4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己最大对其数的整数倍处，结构体的整数倍处，结构体
// 的整体大小就是所以最大对其数（含嵌套）的整数倍；
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
// 动态内存管理
// 1.void* malloc(size_t);返回一个给定空间大小的空指针
// 2.void* relloc(*p,size_t);给目标空间扩指定的空间大小
// 3.void* calloc(size_t num, size_t size)；开辟某个类型的空间多少个；
// 使用注意:
// 可能会开辟失败，所以不要直接用原指针接收，导致原本的数据也丢失了；
// 
//例题分享
// 动态内存管理经典题目
// 1.
//void GetMemory(char* p)一个指针变量因此用指针来接收
//{
//	p = (char*)malloc(100);//开辟空间，但这里面都是临时的拷贝，没有对str进行操作；
//}//////////////////////////并且这里是在堆区创建的空间，退出这个函数后申请的空间不会销毁，
//                           在下文中也找不到这个空间，于是就会导致内存泄漏；
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);//这里传的是指针变量而不是指针的地址，所以这里是传值调用
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
//	char p[] = "hello world";//注意在这里创建字符数组的意思是在栈区上申请空间
//	return p;                //意味这退出函数后这个函数的生命周期结束，此时的内存还给操作系统
 //}                         无法访问；
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
//这里写一段代码与上文作比较
//int* Test()
//{
//    int a = 9;
//    return &a;这里也是一样在栈区上申请的空间，退出后销毁
//}
//int main()
//{
//    int* n = Test();
//    //printf("hehe");
//    printf("%d", *n);
//}
//这里还有一个对比
//int Test()
//{
//    int a = 9;
//    return a;像这种返回值是会先放在寄存器上返回给主函数，所以不会销毁；
//}
//int main()
//{
//    int n = Test();
//    printf("hehe\n");
//    printf("%d", n);
//}
// 3.这段代码炸一看没有问题，但务必切记在堆上分配了空间一般都意味必须要我们自己free释放；
//void Getmemory(char** p,int num)下面传的是指针地址，那么这里拿二级指针接收；
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
//  free(str);//在这之后就无法使用了
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

//柔性数组：结构体中最后一个数组它的空间可以不固定;
//struct STU {
//	int x;
//	int arr[];//第一种写法
//};
//struct STU1 {
//	int x;
//	int arr[0];//第二种写法
//};
//int main()
//{
//	printf("%d", sizeof(struct STU));//这种写法计算出的结果为4，意味着此时结构体此时不会计算数组大小
//	return 0;
//}
//int main()
//{
//	struct STU* s1;
//	struct STU* tmp = (struct STU*)malloc(sizeof(struct STU) + 40);柔性数组的使用
//	assert(tmp);
//	s1 = tmp;
//	for (int i = 0; i < 10; i++)
//	{
//		s1->arr[i] = i + 1;
//		printf("%d ", (s1->arr)[i]);
//	}
//	return 0;
//}

//内存中空间的划分
//
//             栈区（向下增长）
//             （局部变量等）
//   
//               内存映射段
// 
//         
//             堆区(向上增长)
//   （malloc,realloc,calloc分配的空间）
// 
// 
//  静态区（只读常量，static修饰的静态变量）
//
//
//


