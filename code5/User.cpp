// User.cpp
#include "User.h"
#include <iostream>
#include <fstream>
#include <iomanip>

const std::string User::userFilePrefix = "user_";

bool User::authenticate(const std::string& password) {
    loadUser();
    // Implement password hashing and comparison logic here
    return userPassword == password;
}

void User::registerUser(int userId, const std::string& password) {
    this->userId = userId;
    userPassword = password;
    balance = 0.0;
    saveUser();
}

void User::deposit(double amount) {
    loadUser();
    balance += amount;
    saveUser();
}

bool User::withdraw(double amount) {
    loadUser();
    if (amount <= balance) {
        balance -= amount;
        saveUser();
        return true;
    }
    return false;
}

bool User::transfer(double amount) {
    loadUser();
    if (amount <= balance) {
        balance -= amount;
        saveUser();
        return true;
    }
    return false;
}

void User::printReceipt() const {
    loadUser();
    std::string receiptFile = userFilePrefix + std::to_string(userId) + "_receipt.txt";
    std::ofstream file(receiptFile);
    if (file.is_open()) {
        file << "User ID: " << userId << "\n";
        file << "Balance: " << balance << "\n";
        file.close();
        std::cout << "Receipt saved to " << receiptFile << "\n";
    } else {
        std::cerr << "Error saving receipt\n";
    }
}

void User::loadUser() {
    std::string userFile = userFilePrefix + std::to_string(userId) + ".txt";
    std::ifstream file(userFile);
    if (file.is_open()) {
        file >> userPassword >> balance;
        file.close();
    } else {
        std::cerr << "Error loading user data\n";
    }
}

void User::saveUser() const {
    std::string userFile = userFilePrefix + std::to_string(userId) + ".txt";
    std::ofstream file(userFile);
    if (file.is_open()) {
        file << userPassword << "\n" << balance;
        file.close();
    } else {
        std::cerr << "Error saving user data\n";
    }
}
