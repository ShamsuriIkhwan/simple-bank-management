// Admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>

class Admin {
public:
    bool authenticate(const std::string& password);
    void addUser(const User& user);
    int getUserCount() const;

private:
    std::string adminPassword;
    std::vector<User> users;
    static const std::string adminFile;

    void loadAdmin();
    void saveAdmin() const;
};

#endif
