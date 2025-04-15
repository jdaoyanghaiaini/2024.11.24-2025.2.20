package FactoryPattern;

public class AdminFactory implements IFactoryUser{
    @Override
    public User createUser(String name, int userId) {
        return new AdminUser(name,userId);
    }
}
