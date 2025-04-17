public class Test {
    public static void main(String[] args) {
        MyList myList = new MyList();
        myList.addFirst(1);
        myList.addFirst(2);
        myList.addFirst(3);
        myList.addFirst(4);
        myList.addFirst(5);
        myList.display();
        System.out.println(myList.contains(5));
        myList.addLast(0);
        myList.display();
        myList.addIndex(0,0);
        myList.display();
        myList.addIndex(6,1);
        myList.display();
        myList.addIndex(0,-1);
        myList.display();
        myList.removeAllKey(1);
        myList.display();
        myList.remove(5);
        myList.display();
        }
}
