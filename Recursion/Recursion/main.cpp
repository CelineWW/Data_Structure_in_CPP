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
void chooseReward(string);
void countNames(const DynamicQueue&);
void makeOrder(DynamicQueue&);
void displayLine(const DynamicQueue&);
void addName(DynamicQueue&);
void raffleCustomer(const DynamicQueue&);
void chooseReward(string);

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
                addName(waitingList);
                break;
            case 2:
                makeOrder(waitingList);
                break;
            case 3:
                countNames(waitingList);
                break;
            case 4:
//                cout << waitingList.raffleTicket();
                raffleCustomer(waitingList);
                break;
            case 5:
                displayLine(waitingList);
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





// ********************************************************
// name:      countNames()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     int DynamicQueue::numNodes
// The countNames print the number of people in line      *
// ********************************************************
void countNames(const DynamicQueue& line) {
    cout << "Number of people in the line: " << line.numNodes() << endl << endl;
}


// ********************************************************
// name:      countNames()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     int DynamicQueue::numNodes
// The countNames print the number of people in line      *
// ********************************************************
void makeOrder(DynamicQueue& line) {
    cout << line.deleteNode() << ", you can order now!" << endl << endl;
}


// ********************************************************
// name:      countNames()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     int DynamicQueue::numNodes
// The countNames print the number of people in line      *
// ********************************************************
void displayLine(const DynamicQueue& line) {
    cout << endl;
    line.displayList();
    cout << endl;
}


// ********************************************************
// name:      countNames()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     int DynamicQueue::numNodes
// The countNames print the number of people in line      *
// ********************************************************
void addName(DynamicQueue& line) {
    // take user input for customer name
    string newCustomer;
    bool validName = false;
    while(!validName) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Enter your name: ";
        getline(cin, newCustomer);
        if (newCustomer.size() < 20) {
            validName = true;
        }
        else {
            cout << "Name must be less than 20 characters.\n";
            validName = false;
        }
    }
    
    // Add the new customer into line and assigne a number
    cout << "\nWelcome to Point Loma Seafoods!" << endl;
    cout << "Your raffle number is " << line.appendNode(newCustomer) << endl << endl;
}


// ********************************************************
// name:      countNames()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     int DynamicQueue::numNodes
// The countNames print the number of people in line      *
// ********************************************************
void raffleCustomer(const DynamicQueue& line) {
    int raffled = line.raffleTicket();
    cout << "The winning raffle number is :" << raffled << endl << endl;
    chooseReward(line.getName(raffled));
}

// ********************************************************
// name:      countNames()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     int DynamicQueue::numNodes
// The countNames print the number of people in line      *
// ********************************************************
void chooseReward(string winner) {
    // Display reward menu
    cout << winner << ", do you want:" << endl;
    cout << "1. A free t-shirt" << endl;
    cout << "2. A free side dish" << endl;
    // Take user input from reward options
    int choice = 0;
    while(choice != 1 && choice != 2) {
        cout << "Choose your Reward: ";
        cin >> choice;
        if (cin.fail()){
            cout << "Invalid Choice. Enter again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1:
                cout << winner << ", you're going to look great in your new tee!\n" << endl;
                break;
            case 2:
                cout << winner << ", enjoy your extra yummy side dish.\n" << endl;
                break;
            default:
                cout << "Sorry, you only have two options." << endl;
        }
    }
}
