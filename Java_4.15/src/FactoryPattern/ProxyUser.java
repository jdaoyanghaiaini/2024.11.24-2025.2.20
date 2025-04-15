package FactoryPattern;

public class ProxyUser {
    User realUser;

    public ProxyUser(User realUser) {
        this.realUser = realUser;
    }

    public void addBook() {
        if(realUser instanceof NormalUser) {
            System.out.println("权限不够");
        }
        else {
            System.out.println("添加书籍名字为：");
        }
    }

    public void borrowBook() {
        if(realUser instanceof NormalUser) {
            System.out.println("选择你要借书的名字");
        }
        else {
            System.out.println("请以普通用户的方式去访问");
        }
    }
}
