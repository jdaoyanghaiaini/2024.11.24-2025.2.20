public class SingletonPattern {
    public static void main(String[] args) {
        EagerInitialization eagerInitialization1 = EagerInitialization.getInstance();
        EagerInitialization eagerInitialization2 = EagerInitialization.getInstance();
        System.out.println(eagerInitialization1 == eagerInitialization2);   //打印true，用的是创建的同一个对象；
    }
}
//这里是饿汉式单例模式:已经在类中创建了一个单例对象，使用时使用公共方法统一访问;
class EagerInitialization {
    private static EagerInitialization instance = new EagerInitialization();
    private EagerInitialization() {

    }

    //static不依赖与类所以这里不用this.
    public static EagerInitialization getInstance() {
        return instance;
    }
}

//这里是懒汉式单例模式:没有创建对象，只有当使用使才创建对象，并返回这个对象;
class LazyInitialization {
    private static LazyInitialization lazyInitialization;

    private LazyInitialization() {

    }

    public static LazyInitialization getInstance() {
        if(lazyInitialization == null) {
            lazyInitialization = new LazyInitialization();
        }
        return lazyInitialization;
    }
}