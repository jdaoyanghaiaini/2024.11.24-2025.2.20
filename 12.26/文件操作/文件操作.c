#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//一.前置概念
// 1.一般有两种文件，程序文件和数据文件
//   程序文件：源程序文件（后缀.c），目标文件，可执行程序（.exe）
//   数据文件：不一定是程序，而是程序运行时读写的数据；
// 2.流：流是一个高度抽象的概念，在程序运行是要在外部读取数据（u盘，磁盘，软盘等）,怎么
//读取？抽象出一种概念流就想一条河流将数据源和程序联通起来，它是读写数据的一种方法；
// 3.标准流
//在我们使用键盘输出数据时，并没有手动打开流，那是怎么输入的呢？因为在c程序中默认打开了三个流；
//stdin-标准输入流，大多数环境中从键盘输入，scanf函数就是从标准输入流中读取数据
//stdout-标准输出流，输出显示器界面，printf
//stderr-标准错误流，输出到显示器界面；
// 这三个流的类型是：FILE* ————文件指针；
// c语言中，就是通过FILE*的文件指针来维护流的各种操作的；
//二.文件操作
// 1.每个被使用的文件都在内存中开辟了一个内存信息区（用来存放内存的各种信息），实际上是一个结构体被重
//命名为FILE
//
// 2.文件的打开和关闭
//int main()
//{
  //FILE* pf = fopen("date.txt", "r");
  //这是第一种写法当打开文件就在当前源文件的路径时可用；
  //FILE* pf=fopen("D:\\代码管理\\代码练习\\文件操作\\date.txt","r")
  //这是第二种写法表示表示绝对路径；
//	FILE* pf = fopen(".\\..\\date.txt", "w");
//  //这是第三种写法表示相对路径	
//  //.表示当前路径
//  //..表示上一级路径
//  // 	
//	if (pf == NULL)
//	{
//		perror("打开失败");
//		return 0;
//	}
//	fclose(pf);//关闭文件后pf依旧指向那个地址记得置空
//	pf = NULL;
//}
// 2.1文件打开的方式
//    "r"：只读
//    "w"：只写
//    "a"：追加
//   "rb"：只读（二进制）
// 上面的可以和b自由组和形成新的模式
//   "r+"：为了读写打开一个文件
//   "w+"：为了读写创建一个文件
//   "a+"：打开一个文件，在文件尾进行读写
//   "rb+"为了读和写打开一个文件（二进制）
//  上面的可以和b自由组合形成新的模式
// 2.2文件的顺序读写（顺序读写函数）
//   int fputc(int character,FILE* stream);这个函数打印失败返回EOF
//   int fgetc(stream）从流中读取数据，读取到文件末尾返回EOF
//   char* fgets(*ptr,num,stream);读取到num-1个字符，末尾自动放置‘\0’（到达换行符或文件末尾也不读了）
//   它的返回值其实就是它本身*ptr所以一般不接收，而当它读取到第一个便是文件末尾则返回NULL
//   char* fputs(*ptr,stream)读取成功无返回值，失败返回EOF
//   fscanf(stream,const char* format,...)//其实这俩与scanf和printf相比就是多加了一个指定流的概念
//   fprintf(stream,const char* format,...)这里的...叫做可变参数列表，及参数个数不确定；
//   sprint sscanf这个与上面相似用于格式化输出/输入到字符串
//   size_t fread(void* ptr,size_t size,size_t count,FILE* streanm)用于二进制的读
//   size_t fwrite(输出的地址，一个元素有多大，个数，流)用于二进制的写，这和上面的参数一致；
//  2.3文件的随机读写
//   int fseek(FILE* stream,long,int offset,int origin);成功返回0，失败返回非0；
//            offset;文件指针的位置
//                  SEEK_SET：开头
//                  SEEK_CUR：当前位置
//                  SEEK_END：末尾
//            origin:偏移量；
//   long int fteel(FILE* stream);返回文件指针相对于起始位置的偏移量
//   void rewind(FILE* stream)；让文件指针重回开头；
//  3.文件结束的标志
//   int ferror（FILE* stream）;如果不是正常读取到eof结束文件，那么他会返回一个非0值，否则返回0；
//   int feof（FILE* stream）；正常读取返回非0，非正常读取返回为非0值；
// 4.文件缓冲区
//   我们从键盘输入数据不会直接传到电脑，而是会等待文件缓冲区存满或其他情况才由操作系统统一拿过去；
//
//int main()
//{
//	int i = 0;
//	FILE* pf = fopen(".\\creat.txt", "a");
//	if (pf == NULL)
//	{
//		perror("pf is null");
//		return 1;
//	}
//	char arr[20] = {0};
//	fgets(arr, 20, stdin);
//	fputs(arr, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
// 4.判断文件是否读取结束
//   判断返回值是否为EOF（fgetc）或者NULL（fgets）
//   二进制文件的读取结束判断：判断返回值是否小于要读的个数
//   fread判断返回值是否小于要读的个数； 
//