package SeqList;

import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        MyArrayList myArrayList = new MyArrayList();
        myArrayList.add(1);
        myArrayList.add(2);
        myArrayList.add(3);
        myArrayList.add(4);
        myArrayList.add(5);
        myArrayList.add(4,3);
        myArrayList.display();
        System.out.println(myArrayList.contains(2));    //true
        System.out.println(myArrayList.get(3));         //3
        System.out.println(myArrayList.indexOf(3));     //2
        myArrayList.set(5,4);                           //1 2 3 4 4 5
        myArrayList.display();
        System.out.println();
        System.out.println(myArrayList.size());                             //6
        myArrayList.remove(4);                //1 2 3 4 5
        myArrayList.display();
    }
}
