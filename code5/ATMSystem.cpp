// ATMSystem.cpp
#include "ATMSystem.h"
#include <iostream>

void ATMSystem::start() {
    int choice;
    do {
        std::cout << "1. Admin\n2. User\n3. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2: {
                int userId;
                std::cout << "Enter user ID: ";
                std::cin >> userId;
                if (userId >= 1 && userId <= 30) {
                    userMenu(userId);
                } else {
                    std::cout << "Invalid user ID\n";
                }
                break;
            }
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 3);
}

void ATMSystem::adminMenu() {
    std::string adminPassword, userPassword;
    std::cout << "Enter admin password: ";
    std::cin >> adminPassword;

    if (admin.authenticate(adminPassword)) {
        std::cout << "Authentication successful\n";
        int userCount = admin.getUserCount();
        if (userCount < 30) {
            User newUser;
            std::cout << "Enter user password: ";
            std::cin >> userPassword;
            newUser.registerUser(userCount + 1, userPassword);
            admin.addUser(newUser);
        } else {
            std::cout << "User limit reached\n";
        }
    } else {
        std::cout << "Authentication failed\n";
    }
}

void ATMSystem::userMenu(int userId) {
    std::string userPassword;
    std::cout << "Enter user password: ";
    std::cin >> userPassword;

    if (users[userId - 1].authenticate(userPassword)) {
        std::cout << "Authentication successful\n";
        int userChoice;
        do {
            std::cout << "1. Deposit\n2. Withdraw\n3. Transfer\n4. Print Receipt\n5. Logout\nEnter choice: ";
            std::cin >> userChoice;
            switch (userChoice) {
                case 1: {
                    double amount;
                    std::cout << "Enter deposit amount: ";
                    std::cin >> amount;
                    users[userId - 1].deposit(amount);
                    break;
                }
                case 2: {
                    double amount;
                    std::cout << "Enter withdraw amount: ";
                    std::cin >> amount;
                    if (users[userId - 1].withdraw(amount)) {
                        std::cout << "Withdrawal successful\n";
                    } else {
                        std::cout << "Insufficient funds\n";
                    }
                    break;
                }
                case 3: {
                    int recipientId;
                    double amount;
                    std::cout << "Enter recipient ID: ";
                    std::cin >> recipientId;
                    std::cout << "Enter transfer amount: ";
                    std::cin >> amount;
                    if (userId != recipientId && users[recipientId - 1].transfer(amount)) {
                        std::cout << "Transfer successful\n";
                    } else {
                        std::cout << "Transfer failed\n";
                    }
                    break;
                }
                case 4:
                    users[userId - 1].printReceipt();
                    break;
                case 5:
                    std::cout << "Logging out...\n";
                    break;
                default:
                    std::cout << "Invalid choice\n";
            }
        } while (userChoice != 5);
    } else {
        std::cout << "Authentication failed\n";
    }
}
