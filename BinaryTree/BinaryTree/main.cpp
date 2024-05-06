/*
 *
 * Celine Wang
 *
 * Chapter 21, Programming BinaryTree with IntBinaryTree class
 *
 * May 2024
 *
 */


#include <iostream>
#include <limits>
#include "IntBinaryTree.h"
using namespace std;


// Function declarations
void displayInstruction();
void displayMenu();
void insertInteger(IntBinaryTree&);
void exitProgram();


int main() {
    displayInstruction();
    
    // Create a WordStack object.
    IntBinaryTree tree;
    
    
    int choice = 0;
    // Continually display the menu until user choose to quit
    while(choice != 6) {
        displayMenu();
        cout << "Please choose a menu option: ";
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
                insertInteger(tree);
                break;
            case 2:
                tree.displayInOrder();
                break;
            case 3:
                tree.displayLeafCount();
                break;
            case 4:
                tree.displayTreeHeight();
                break;
            case 5:
                tree.displayTreeWidth();
                break;
            case 6:
                exitProgram();
                break;
            default:
                cout << "Invalid enter! Choose an option between 1-7.\n";
        }
    }
    return 0;
}

// ********************************************************
// name:      displayInstruction
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayMenu function display the instruction of    *
// story game (explain the menu)                          *
// ********************************************************
void displayInstruction() {
    cout << "\n****** Binary Tree Operation System ******\n\n";
    cout << "This program is designed to create your binary tree and display data about the tree.\n";
    cout << "You have the following options:\n";
    cout << "1. Insert one integer into the tree\n";
    cout << "2. Display the tree (in order)\n";
    cout << "3. Display Leaf Count - Counts the number of lead nodes in the tree\n";
    cout << "4. Display Tree Height - Counts the height of the tree\n";
    cout << "5. Display Tree Width - Counts the width (largest numbe of nodes in the same level) of the tree\n";
    cout << "6. Exit - exit the program\n\n";
    cout << " ------ You can start to create your tree now------> \n\n";
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayMenu function display the menu of binary    *
// tree processing options                                *
// ********************************************************
void displayMenu() {
    cout << "\nBinary Tree Menu\n";
    cout << "1. Insert An Integer\n";
    cout << "2. Display The Tree (In Order)\n";
    cout << "3. Display Leaf Count\n";
    cout << "4. Display Tree Height\n";
    cout << "5. Display Tree Width\n";
    cout << "6. Exit\n\n";
}

// ********************************************************
// name:      insertInteger
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     IntBinaryTree::insert()
// The insertInteger function take user input of an       *
// and validate it, create a new node with this value and *
// insert to the tree                                     *
// ********************************************************
void insertInteger(IntBinaryTree &myTree) {
    int num;
    cout << "Insert: ";
    cin >> num;
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter an integer number! ";
        cout << "Insert: ";
        cin >> num;
    }
    myTree.insertNode(num);
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
    cout << "Bye! Hope you enjoyed binary tree operation system!\n";
    cout << "-----------------------------------------------------\n";
}



