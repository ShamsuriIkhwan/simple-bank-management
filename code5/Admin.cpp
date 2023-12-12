// Admin.cpp
#include "Admin.h"
#include <iostream>
#include <fstream>

const std::string Admin::adminFile = "admin.txt";

bool Admin::authenticate(const std::string& password) {
    loadAdmin();
    // Implement password hashing and comparison logic here
    return adminPassword == password;
}

void Admin::addUser(const User& user) {
    loadAdmin();
    users.push_back(user);
    saveAdmin();
}

int Admin::getUserCount() const {
    return users.size();
}

void Admin::loadAdmin() {
    std::ifstream file(adminFile);
    if (file.is_open()) {
        file >> adminPassword;
        file.close();
    } else {
        std::cerr << "Error loading admin credentials\n";
    }
}

void Admin::saveAdmin() const {
    std::ofstream file(adminFile);
    if (file.is_open()) {
        file << adminPassword;
        file.close();
    } else {
        std::cerr << "Error saving admin credentials\n";
    }
}
