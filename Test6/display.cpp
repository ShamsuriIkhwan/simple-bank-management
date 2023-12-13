// display.cpp

#include <iostream>
#include <cstdlib>
#include "display.h"  // Include necessary header file(s)
#include "BankFunctions.h"
using namespace std;

void displayMenu() {
    int choice;
    cout << "\n\n\n\n\n\t\t\t\tWelcome to our Bank System";
    
    for (int i = 0; i < 6; ++i) {
        // Assuming 'fordelay' is defined somewhere
        fordelay(100000000);
        cout << ".";
    }

    menu:
    system("cls");
    system("color 4");
    cout << "\t\t\t ---------------------" << endl;
    cout << "\t\t\t|   STATE BANK OF PP  |" << endl;
    cout << "\t\t\t ---------------------" << endl;
    system("color 3");
    cout << "\n\n\t\t\t\t MENU\n";
    cout << "\n\t\t1. Employee ";
    cout << "\n\t\t2. Customer ";
    cout << "\n\t\t3. Exit ";
    cout << "\n\t\tEnter Your Choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            employee();
            break;
        case 2:
            customer();
            break;
        case 3:
            close();
            break;
        default:
            cout << "Invalid Input! Try Again...\n";
            // Assuming 'fordelay' is defined somewhere
            fordelay(1000000000);
            goto menu;
    }
}
