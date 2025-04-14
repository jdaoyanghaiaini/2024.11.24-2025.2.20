package SeqList;

public interface ISeqList {
    public void add(int data);
    // 在 pos 位置新增元素
    public void add(int pos, int data);
    // 判定是否包含某个元素
    public boolean contains(int toFind);
    // 查找某个元素对应的位
    public int indexOf(int toFind);
    // 获取 pos 位置的元素
    public int get(int pos);
    // 给 pos 位置的元素设为 value
    public void set(int pos, int value);
    //删除第⼀次出现的关键字key
    public void remove(int toRemove);
    // 获取顺序表⻓度
    public int size();
    // 清空顺序表
    public void clear();
    public void display();
}
