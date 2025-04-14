package SeqList;

import java.util.Arrays;

import static SeqList.Constant.ARRAYLISTEMPTY;
import static SeqList.Constant.UNLEGALLYPOS;

public class MyArrayList implements ISeqList {
    private int[] elem;
    private int usedSize;
    public static final int DEFAULT_SIZE = 10;

    MyArrayList() {
        this.elem = new int[DEFAULT_SIZE];
    }
    MyArrayList(int initialSize) {
        this.elem = new int[initialSize];
    }

    @Override
    public void add(int data) {
        if(isFull()) grow();
        else {
            this.elem[usedSize] = data;
            this.usedSize++;
        }
    }

    @Override
    public void add(int pos, int data) {
        //判断是否为空
        if(isEmpty()) {
            throw new ArrayListIsEmptyException(ARRAYLISTEMPTY);
        }
        //判断pos位置是否有效;
      if(checkPos(pos)) {
          throw new UnLegallyPosException(UNLEGALLYPOS);
      }
      if(isFull(1)) grow();
      for(int i=this.usedSize-1;i>=pos;i--) {
          this.elem[i+1] = this.elem[i];
      }
      this.elem[pos] = data;
      this.usedSize++;
    }

    private boolean checkPos(int pos) {

        if(pos<0 || pos >= this.usedSize) {
            return true;
        }
        return false;
    }

    @Override
    public boolean contains(int toFind) {
        for(int i=0;i<this.usedSize;i++) {
            if(this.elem[i] == toFind)  return true;
        }
        return false;
    }

    @Override
    public int indexOf(int toFind) {
        for(int i=0;i<this.usedSize;i++) {
            if(this.elem[i] == toFind)  return i;
        }
        return -1;
    }

    @Override
    public int get(int pos) {
        if(checkPos(pos)) {
            throw new UnLegallyPosException(UNLEGALLYPOS);
        }
        return this.elem[pos-1];
    }

    @Override
    public void set(int pos, int value) {
        if(checkPos(pos)) {
            throw new UnLegallyPosException(UNLEGALLYPOS);
        }
        this.elem[pos-1] = value;
    }

    @Override
    public void remove(int toRemove) {
        if(contains(toRemove)) {
            for(int i=indexOf(toRemove);i<usedSize-1;i++) {
                this.elem[i] = this.elem[i+1];
            }
            this.usedSize--;
        }
        else
            System.out.println("没有该元素");
    }

    @Override
    public int size() {
        return this.usedSize;
    }

    @Override
    public void clear() {
        this.usedSize = 0;
    }

    @Override
    public void display() {
        for(int i=0;i<this.usedSize;i++) {
            System.out.print(this.elem[i]+" ");
        }
    }

   private boolean isFull() {
        if(this.elem.length == usedSize) return true;
        else
            return false;
   }

    private boolean isFull(int x) {
        if(this.elem.length+x == usedSize) return true;
        else
            return false;
    }
    private boolean isEmpty() {
        if(this.usedSize == 0)
            return true;
        return false;
    }
   private void grow() {
        this.elem = Arrays.copyOf(this.elem,this.elem.length*2);
   }
}
