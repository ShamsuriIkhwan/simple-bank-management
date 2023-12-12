// User.h
#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    bool authenticate(const std::string& password);
    void registerUser(int userId, const std::string& password);
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(double amount);
    void printReceipt() const;

private:
    int userId;
    std::string userPassword;
    double balance;
    static const std::string userFilePrefix;

    void loadUser();
    void saveUser() const;
};

#endif
