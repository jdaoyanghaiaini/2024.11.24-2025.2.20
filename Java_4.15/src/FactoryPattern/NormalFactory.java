package FactoryPattern;

public class NormalFactory implements IFactoryUser{
    @Override
    public User createUser(String name, int userId) {
        return new NormalUser(name,userId);
    }
}
