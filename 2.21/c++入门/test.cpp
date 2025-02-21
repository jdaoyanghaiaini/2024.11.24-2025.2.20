//一、命名空间
//命名空间是为了解决c语言在定义标识符
// 与库中函数名或多人协作时多人同时定义同一个标识符而报错的问题
#include<iostream>
using namespace std;
//1.标准库的命名空间展开
//using namespace std;//使用标准库必须展开指定的命名空间；
//int main()
//{
//	//cout << "hehe" << endl;直接使用不展开命名空间产生报错
//	cout << "hehe" << endl;//展开后可以使用；
//	return 0;
//}
//2.指定某个展开
//int main()
//{
//  ::这个符号是作用域限定符，用于限定指定的域；
//	std::cout << "hehe" << std::endl;
//	这种展开方式适合的是不经常调用的函数
//	return 0;
//}
//对于经常调用的函数，我们通常使用下面这种写法
//using std::cout;
//using std::endl;
//int main()
//{
//	cout << "hehe" << endl;
//	return 0;
//}
//int a = 0;
//namespace daoyang
//{
//	int a = 0;
//	int b = 0;
//}
//int main()
//{
//	int a = 3;
//	cout << a << endl;
//	cout << daoyang::a << endl;
//	return 0;
//}
//c++域的搜索是有优先级的指定 >> 当前域 >> 全局域
//二、缺省参数
//1.缺省参数指的是函数的参数部分是默认值，传参数了那么就是它传来的参数
//void Test(int x = 4)
//{
//	cout << x << endl;
//}
//int main()
//{
//	Test(10);//10
//	Test();//4
//}
//2.有两种缺省参数：半缺省，全缺省，它们指的是函数的参数是否全缺省
//三、函数重载
//c++允许存在同名函数，这几个函数的功能类似；
//存在下面几种情况
//1.参数类型不同
//2.参数的位置不同
//3.参数的个数不同
//这里的底层其实是函数的名字修饰原理
//特别注意：返回值不同不算做是函数重载；
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Add(double x, double y)
//{
//	return x + y;
//}
//int Add(int x, double y)
//{
//	return x + y;
//}
//double Add(double x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	cout << Add(10, 15) << endl;
//	cout << Add(11.2, 125) << endl;
//	return 0;
//}
//四、引用
//引用类似指针，但不能完全代替指针，但在某些方面有其独特的优势；
//int main()
//{
//	int a = 54;
//	int& b = a;
//	cout << b << endl;
//	cout << a << endl;引用相当于是起别名的效果
//	return 0;
//}
//引用特性
//	引用必须初始化
//	引用只能引用一个实体
//	一个实体可以有多个引用
//引用有下面几种用处
//	1.引用做返回值：不会产生临时变量，提高程序运行速率；
//int& Add(int x, int y)
//{
//	int c = x + y;
//	return c;
//}
//int main()
//{
//	cout << Add(x, y) << endl;
//	return 0;
//	这种写法是不对的，因为c出了这个域后，该空间便自动返回给操作系统，会导致随机值情况；
//}
//int& Add(int x, int y)
//{
//	static int c = x + y;//该变量开辟在静态区，出域后不会销毁，那么这里便可以返回引用；
//	return c;
//}
//	2. 引用做参数
//void Swap(int& x, int& y)
//{
//	int t = y;
//	y = x;
//	x = t;
//}
//int main()
//{
//	int x = 1, y = 2;
//	cout << x << " " << y << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}
//	3.常引用
//这里涉及到了权限的扩大、缩小、平移
//c++中权限可以平移，可以缩小，不能够扩大；
//int main()
//{
//    const int a = 10;
//    //int& ra = a;   // 该语句编译时会出错，a为常量
//    const int& ra = a;
//    // int& b = 10; // 该语句编译时会出错，b为常量
//    const int& b = 10;
//    double d = 12.34;
//    //int& rd = d; // 该语句编译时会出错，类型不同
//    const int& rd = d;
//    //不仅仅如此，在进行隐性提升时，都会产生一个零时变量
//    //用来存储这个值，这个值拥有常性，即不可更改；
//}
//五、内联函数
//	是一种用空间换时间的方法
//	直接展开不用建立栈帧，这样可以提高运行效率
//	内联只是对编译器的一个提议，至于用不用内联，取决于编译器
//顺便一提：c语言中解决的方法时创建宏函数提高效率
//#define (参数列表) 替换文本
//	注意：不使用分号
//#define Add(x,y) (x)+(y)
//int main()
//{
//	cout << Add(10, 11) << endl;
//	return 0;
//
//}
//六、auto关键字
//auto 可以自动推算类型；
//七、基于范围的for循环
//	这是一个新语法，挺好用
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	for (int e : arr)
//		cout << e << " " << endl;
//	return 0;
//}
//可以和引用搭配着用
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	for (int& e : arr)
	{
		e *= 2;
		cout << e << endl;
	}
	for (int e : arr)
		cout << e << endl;
	return 0;
}