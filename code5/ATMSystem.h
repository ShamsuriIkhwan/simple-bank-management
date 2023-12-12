// ATMSystem.h
#ifndef ATM_SYSTEM_H
#define ATM_SYSTEM_H

#include "Admin.h"
#include "User.h"

class ATMSystem {
public:
    void start();

private:
    Admin admin;
    User users[30];

    void adminMenu();
    void userMenu(int userId);
};

#endif
