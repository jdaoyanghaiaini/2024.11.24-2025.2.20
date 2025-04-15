package FactoryPattern;

public class FactoryPattern {
    //将创建对象的过程打包成一个类，用一个类来统一创建对象，这个就是工程模式
    public static void main(String[] args) {
        AdminFactory adminFactory = new AdminFactory();
        NormalFactory normalFactory = new NormalFactory();
        User admin = adminFactory.createUser("张三",1);
        User normal1 = normalFactory.createUser("李四",2);
        User normal2 = normalFactory.createUser("王五",3);
        //=============================================================================

        ProxyUser proxyAdmin = new ProxyUser(admin);
        ProxyUser proxyNormal = new ProxyUser(normal1);

        proxyAdmin.addBook();
        proxyAdmin.borrowBook();

        proxyNormal.addBook();
        proxyNormal.borrowBook();
    }
}
