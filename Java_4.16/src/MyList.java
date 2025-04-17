public class MyList implements ISingleList {
    ListNode head;
    static class ListNode {
        public int val;
        public ListNode next;
        ListNode(int val) {
            this.val = val;
        }

    }

    @Override
    public void addFirst(int data) {
        ListNode newNode = createNode(data);
        newNode.next = head;
        head = newNode;
    }

    @Override
    public void addLast(int data) {
        ListNode newNode = createNode(data);
        if(head == null) {
            head = newNode;
        }
        else {
            ListNode tail = head;
            while(tail.next!=null) {
                tail = tail.next;
            }
            tail.next = newNode;
        }
    }

    @Override
    public void addIndex(int index, int data) {
        try {
            if(!checkIndex(index)) {
                throw new UnLegallyIndexException("index 位置不合法");
            }
            else {
                if(index == 0)  {
                    addFirst(data);
                    return;
                }
                if(index == size()){
                    addLast(data);
                    return;
                }
                //中间插入
                ListNode cur = head;
                ListNode newNode = createNode(data);
               for(int i=0;i<index-1;i++) {
                   cur = cur.next;
               }
               newNode.next = cur.next;
               cur.next = newNode;
            }
        }catch (UnLegallyIndexException e) {
            e.printStackTrace();
        }
    }

    @Override
    public boolean contains(int key) {
        ListNode cur = head;
        while(cur!=null) {
            if(cur.val == key) {
                return true;
            }
            cur = cur.next;
        }
        return false;
    }

    @Override
    public void remove(int key) {
        if(!contains(key)) {
            System.out.println("没有该元素");
        }
        else {
            ListNode del = head;
            if(del.val == key) {
                head = del.next;
                return;
            }
            while(del.next!=null) {
                if(del.next.val == key) {
                    del.next = del.next.next;
                }
                else {
                    del = del.next;
                }
            }
        }
    }

    @Override
    public void removeAllKey(int key) {
        if (head == null) {
            System.out.println("空链表不可删除");
        } else {
            ListNode del = head.next;
            ListNode prev = head;
            while(del!=null) {
                if(del.val == key) {
                    prev.next = del.next;
                    del = prev.next;
                }
                else {
                    prev = del;
                    del = del.next;
                }
            }
            if(head.val == key) {
                head = head.next;
            }
        }
    }
    @Override
    public int size() {
        ListNode cur = head;
        int i = 0;
        while(cur!=null) {
            i++;
            cur = cur.next;
        }
        return i;
    }

    @Override
    public void clear() {
        ListNode del = head;
        while(del!=null) {
            ListNode nodeNext = del.next;
            del.next = null;
            del = nodeNext;
        }
        //head仍然在引用头节点;
        head = null;
    }

    @Override
    public void display() {
        ListNode cur = head;
        while(cur!=null) {
            System.out.print(cur.val + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    private ListNode createNode(int val) {
        return new ListNode(val);
    }

    private boolean checkIndex(int index) {
        if(index < 0 || index > size()) {
            return false;
        }
        return true;
    }
}
