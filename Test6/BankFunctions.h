// Bank.h

#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>  // Include the necessary header for 'string'
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "display.h"

using namespace std;  // Add this line to resolve the 'string' issue

void fordelay(int j);
void menu_e();
void menu_c();

class Bank {
public:
    void acc_write();
    void modify_account();
    void deposit_withdraw();
    void search_rec();
    void display_all();
    void transfer();
    void read_data();

private:  // Moved the member variables to the private section
    string account_number;
    string name;
    string dob;
    string age;
    string date;
    string address;
    string phone;
    string doc;
    string depo;
    string acc_type;
    string password;
    string interest;
};

#endif // BANK_H
