package Generic;

public class Test {
    //泛型方法:修饰部分<> 返回值  函数体
    public static<E> void Swap(E[] array,int a, int b) {
        E tmp = array[a];
        array[a] = array[b];
        array[b] = tmp;
    }
    public static void main(String[] args) {
        String[] str = {"张三","李四"};
        Integer[] integers = {20,21};
        Swap(str,0,1);
        Swap(integers,0,1);
        for(int i=0;i<=1;i++) {
            System.out.println(str[i]);
            System.out.println(integers[i]);
        }
    }
    //包装类有关面试题,涉及底层
    public static void main2(String[] args) {
        Integer i = 127;
        Integer j = 127;

        Integer ii = 200;
        Integer jj = 200;

        //在-127~128之间是在cache数组内拿对象，所以它们两个是一样的
        //超过这个范围之后会重新new一个对象，故不相同;
        System.out.println(i == j);
        System.out.println(jj == ii);
    }
    //包装类基本介绍
    public static void main1(String[] args) {
        //包装类就是将基本类型封装成一个类，让它可以完成泛型编程

        //这是手动装箱过程
        int i = 5;
        Integer ii = Integer.valueOf(i);

        //这是自动装箱过程
        Integer jj = 5;

        System.out.println(ii);
        System.out.println(jj);
    }
}
class Node<T> {
    private T date;

    public void setDate(T date) {
        this.date = date;
    }
}
class StringNode extends Node<String> {
    //这里涉及到的是桥接方法

    @Override
    public void setDate(String str) {
        super.setDate(str);
    }
}