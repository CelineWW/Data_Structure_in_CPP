/*
 *
 * Celine Wang
 *
 * Chapter 18, Programming NecklaceBuilder with BeadList class
 *
 * Mar 2024
 *
 */

#include <iostream>
#include <vector>
#include <limits>
#include "BeadList.h"
using namespace std;

// Function declarations
void displayMenu();
void append(BeadList &);
void insert(BeadList &);
void deleteBead(BeadList &);
void display(const BeadList &);
void search(const BeadList &);
void exitProgram();

int main() {
    // Define a BeadList object
    BeadList necklace;
    
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
                append(necklace);
                break;
            case 2:
                insert(necklace);
                break;
            case 3:
                deleteBead(necklace);
                break;
            case 4:
                display(necklace);
                break;
            case 5:
                search(necklace);
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


/*
 High level validation
 append: bead - in colors array;
 search: bead - in colors array;
 insert: bead - in colors array,  0 < position <= beadsCount;
 delete: 0 <= postion < beadsCount.
 */


// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayMenu function display the menu of necklace  *
// building options                                       *
// ********************************************************
void displayMenu() {
    cout << "\nBuilding Necklace Menu\n";
    cout << "1. Append\n";
    cout << "2. Insert\n";
    cout << "3. Delete\n";
    cout << "4. Print\n";
    cout << "5. Search\n";
    cout << "6. Exit\n\n";
}

// ********************************************************
// name:      append
// called by: main
// passed:    &necklace_p
// returns:   nothing
// calls:     BeadList.appendNode(string)
//            BeadList.colorCheck(string)
// The append function validate user's input of           *
// bead materical, then call BeadList appendNode member   *
// function of necklace object                            *
// ********************************************************
void append(BeadList &necklace_p){
    cin.ignore();     // Clear buffer
    // get valid bead material from user
    string color_p = "";
    cout << "\nEnter Beads Material: ";
    getline(cin, color_p);
    while(!necklace_p.colorCheck(color_p)) {
        cout << "Error: " << color_p << " is not a metal that we carry.\n";
        cout << "Enter Bead Metal: ";
        getline(cin, color_p);
    }
    necklace_p.appendNode(color_p);
}


// ********************************************************
// name:      insert
// called by: main
// passed:    &necklace_p
// returns:   nothing
// calls:     BeadList.insertNode(string)
//            BeadList.colorCheck(string)
// The insert function validate user's input of  bead     *
// materical and position datatype, then call BeadList    *
// insertNode member function of necklace object.         *
// insertNode take care of position number validation     *
// ********************************************************
void insert(BeadList &necklace_p){
    cin.ignore();
    
    // Validate the available bead materials
    string color_p = "";
    cout << "Enter Beads Material: ";
    getline(cin, color_p);
    while(!necklace_p.colorCheck(color_p)) {
        cout << "Error: " << color_p << " is not a metal that we carry.\n";
        cout << "Enter Bead Metal: ";
        getline(cin, color_p);
    }
    
    // Validate the position data type
    int position_p;
    cout << "Enter Insert Position: ";
    cin >> position_p;
    cin.ignore();
    if (cin.fail()) {
        cout << "Enter a number for insert position: ";
        cin >> position_p;
        cin.ignore();
    }
    
    // No need to check bead position(the existance of a node)
    necklace_p.insertNode(color_p, position_p);
}

// ********************************************************
// name:      deleteBead
// called by: main
// passed:    &necklace_p
// returns:   nothing
// calls:     BeadList.appendNode(string)
//            BeadList.colorCheck(string)
// The deleteBead function validate user's input of  bead *
// position datatype, then call BeadList deleteNode       *
// member function of necklace object.                    *
// deleteNode take care of position number validation     *
// ********************************************************
void deleteBead(BeadList &necklace_p) {
    // Validate the position data type
    int position_p;
    cout << "What bead position do you wish to delete? ";
    cin >> position_p;
    cin.ignore();
    if (cin.fail()) {
        cout << "Enter a number for delete position: ";
        cin >> position_p;
        cin.ignore();
    }
    
    // No need to check bead position(the existance of a node)
    necklace_p.deleteNode(position_p);
}


// ********************************************************
// name:      display
// called by: main
// passed:    &necklace_p
// returns:   nothing
// calls:     BeadList.displayNode(string)
// The display function call BeadList displayNode         *
// member function of necklace object.                    *
// ********************************************************
void display(const BeadList &necklace_p) {
    necklace_p.displayNode();
}

// ********************************************************
// name:      search
// called by: main
// passed:    &necklace_p
// returns:   nothing
// calls:     BeadList.searchNode(string)
//            BeadList.colorCheck(string)
// The search function validate user's input of  bead     *
// materical, then call BeadList searchNode member        *
// function of necklace object, and display the result.   *
// ********************************************************
void search(const BeadList &necklace_p) {
    
    // Validate the exist bead materials
    string color_p = "";
    cout << "\nEnter color to search for: ";
    cin >> color_p;
    cin.ignore();
    while(!necklace_p.colorCheck(color_p)) {
        cout << "Error: " << color_p << " is not a metal that we carry.\n";
        cout << "Enter color to search for: ";
        cin >> color_p;
        cin.ignore();
    }
    
    
    // Call BeadList serachNode function to get a vector of beads positions.
    vector<int> positions = necklace_p.searchNode(color_p);
    
    // Display positions result
    if (positions.size() == 1 && positions[0] == -1) {           // Not found
        cout << "There is no " << color_p << " beads found.\n";
    }
    else if (positions.size() == 1 && !(positions[0] == -1)) {   // Found only one bead
        cout << "There is a " << color_p << " bead at position (" << positions[0] << ")\n";
    }
    else {   // Found multiple target beads
        cout << "There are " << positions.size() << " " << color_p << " beads at positions (";
        for (int i = 0; i < positions.size(); i++) {
            cout << positions[i];
            if (i < positions.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")\n";
    }
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
    cout << "Bye! I hope you are liking your bead choices.\n";
    cout << "-----------------------------------------------------\n";
}
