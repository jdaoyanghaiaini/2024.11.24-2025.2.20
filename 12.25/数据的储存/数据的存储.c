#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>//offsetof所在的头文件
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
// 两种特殊的结构:enum,union；
// 一.结构体体内存对其
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
// 的整体大小就是所以最大对其数（含嵌套）的整数倍；（要计算嵌套结构体的大小）
// 在设计结构体时将同一类型的放在一起空间浪费较少；
// 例子看test.c
// offsetof计算成员的偏移量
//struct s5 {
//	char a;
//	int y;
//};
//int main()
//{
//	printf("%d ", offsetof(struct s5,a));
//	printf("%d ", offsetof(struct s5,y));
//	printf("%d", sizeof(struct s5));
//	return 0;
//}
//// 二.位段的实现
//位段的成员必须是整形（int，unsign int ，signed int,char）
//位段一个冒号一个数字；
// 定义时不应该去超过数据类型本身最大的内存如int _x:60;超过32
//位段的位是二进制位的意思写了几个就是几个位；
//struct Stu {
//	int _x : 3;
//	int _y : 15;
//	int _k : 13;
//};
//int main()
//{
//	printf("%d", sizeof(struct Stu));
//	return 0;
//}
//位段的内存计算
// 1.先开辟对应类型的大小如int就开辟4个字节，char就开辟1个字节
// 2.在开辟的空间中将位放进去，空间从左往右使用还是从右往左使用不确定       详细见25.结构体2h25min
// 3.当剩下的空间不足一放下一个成员时，空间是浪费还是使用不确定； 
// 各个编译器的处理方法不一样，可见位段不适合跨平台；
// 三.枚举
//enum Color
//{
//	Red,
//	Blue,
//	Green//枚举的对象用逗号隔开，不用分号；
//};
//int main()
//{
//	printf("%d", Red);//这里打印的值是0，枚举第一个定义为0，后面以此增加（可以自己手动改变）
//	return 0;          枚举它可以增加代码的可读性，譬如在写switch开关时用enum去代替数字1.2.3
//}                    可以让代码更容易阅读；
//四.联合体
// 1.联合体（共用体）的成员共用一个空间
// 2.联合体内存大小的计算
//   联合体的大小至少是成员大小
//   当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍
//union s1 {
//	char x;         //1 8 1
//	int y;          //4 8 4
//	int arr[3];     //4 8 4   
//};
//int main()
//{
//	printf("%d", sizeof(union s1));这里的值是12，因为12是最大对齐数4的整数倍；
//}
// 
//union的应用:
//struct BOOK {
//	int princr;
//	char name;
//	char quoto;
//	union other                    
//	{
//		union other1 {                    针对某些情况的时候被描述物有多个相同的特征和
//			int x;                        少许不同的特征，这样子做可以节省空间；
//		};
//		union other {
//			int y;
//		};
//	};
//};
// 
// 
// 
// 
// 
// 
// 五.动态内存管理
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




//六.柔性数组：结构体中最后一个数组它的空间可以不固定;
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


