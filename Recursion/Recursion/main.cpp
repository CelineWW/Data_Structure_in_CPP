/*
 *
 * Celine Wang
 *
 * Chapter 20, Programming Recursion with DynamicQueue class
 *
 * Apr 2024
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "DynamicQueue.h"
using namespace std;

// Function declarations
void displayMenu();
void exitProgram();

int main() {
    displayMenu();
    
    // Create a WordStack object.
    DynamicQueue waitingList;
    
    int choice = 0;
    // Continually display the menu until user choose to quit
    while(choice != 6) {
        displayMenu();
        cout << "Choose your option: ";
        cin >> choice;
        // Continually prompt user input until valid
        if (cin.fail()) {
            cout << "Choose a number from the menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Choose from main menu
        switch (choice) {
            case 1:
                cout << "Option 1" << endl;
                break;
            case 2:
                cout << "Option 2" << endl;
                break;
            case 3:
                cout << "Option 3" << endl;
                break;
            case 4:
                cout << "Option 4" << endl;
                break;
            case 5:
                cout << "Option 5" << endl;
                break;
            case 6:
                exitProgram();
                break;
            default:
                cout << "Invalid enter! Choose an option between 1-6.\n";
        }
    }
    return 0;
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayMenu function display the menu of waiting   *
// list                                                   *
// ********************************************************
void displayMenu() {
    cout << "Point Loma Seafood Waiting List\n";
    cout << "1. Add a name\n";
    cout << "2. Make an Order\n";
    cout << "3. Count Names\n";
    cout << "4. Draw Raffle Winner\n";
    cout << "5. Display Line\n";
    cout << "6. Exit\n\n";
}

// ********************************************************
// name:      exitProgram()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The exitProgram function terminate the program         *
// ********************************************************
void exitProgram() {
    cout << "Thank you for visiting Point Loma Seafoods!\n";
    cout << "-----------------------------------------------------\n";
}
