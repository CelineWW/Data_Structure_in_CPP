/*
 *
 * Celine Wang
 *
 * Chapter 6, Programming menu driven2D Integer
 *
 * Feb 2024
 *
 */


#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Global constants
const int ROWS = 4;
const int COLS = 4;

// Function prototyps
void displayMenu();
void displayArray(const int (&arr)[][COLS], int rows);
void getLocation(const int (&arr)[][COLS], int rows);
void swapColumn(int (&arr)[][COLS], int rows);
void exitProgram();

int main() {
    
    cout << "2D Array Menu Driven Program\n";
    
    // varibles to hold 2D integer array
    int myArray[ROWS][COLS] = {
        {1, 3, 5, 7},
        {9, 11, 13, 15},
        {17, 19, 21, 23},
        {25, 27, 29, 31}
    };
    
    // Prompt user to choose from the menu options
    int choice = 0;
    while(choice != 4) {
        cout << endl;
        displayMenu();
        cout << "\n\nPlease enter your choice: ";
        cin >> choice;
        
        // data validation for the input
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please re-enter please.\n";
            continue;
        }
        
        // call function based on user's choice
        switch (choice){
            case 1:
                displayArray(myArray, ROWS);
                break;
            case 2:
                getLocation(myArray, ROWS);
                break;
            case 3:
                swapColumn(myArray, ROWS);
                break;
            case 4:
                exitProgram();
                break;
            default:
                cout << "Please choose a number from 1 to 4.\n";
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
// The displayMenu function displays the Program menu
// ********************************************************

void displayMenu(){
    cout << "*** Menu ***\n";
    cout << "1. Display Array\n";
    cout << "2. Find My Integer\n";
    cout << "3. Swap Column 1 with Column 3\n";
    cout << "4. Exit";
}

// ********************************************************
// name:      displayArray
// called by: main
// passed:    const int (&arr)[][COLS], int rows
// returns:   nothing
// calls:     nobody
// The displayArray function displays the integer matrix  *
// currently stored in the 2D array
// ********************************************************

void displayArray(const int (&arr)[][COLS], int rows){
    cout << "\nHere is your array:\n";
    for (int i = 0; i < rows; i++ ){
        for (int j = 0; j < COLS; j++){
            cout << right << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// ********************************************************
// name:      getLocation
// called by: main
// passed:    const int (&arr)[][COLS], int rows
// returns:   nothing
// calls:     nobody
// The getLocation function take user's input of a number.*
// Search the number in the array, display a message to   *
// show its location                                      *
// ********************************************************
void getLocation(const int (&arr)[][COLS], int rows){
    int target = 0;
    bool found = false;
    while (true){
        cout << "Enter an integer to locate: ";
        if (cin >> target) {
            for (int i = 0; i < rows; i++ ){
                for (int j = 0; j < COLS; j++){
                    if (arr[i][j] == target) {
                        cout << target << " is located on row " << i + 1 << ", cloumn " << j + 1 << ".\n";
                        found = true;
                        break;
                    }
                }
            }
            if (found == false) {
                cout << target << " is not found in the array.\n";
            }
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an integer.\n";
            continue;
        }
    }
}
       
// ********************************************************
// name:      swapColumn
// called by: main
// passed:    int &array[][COLS], int rows
// returns:   nothing
// calls:     nobody
// The swapColumn function swap the cloumn 1 and cloumn 3 *
// in the array and save the changes.                     *
// ********************************************************
void swapColumn(int (&arr)[][COLS], int rows){
    int tempColumn[rows];
    for (int j = 0; j < rows; j++){
        tempColumn[j] = arr[j][0];
        arr[j][0] = arr[j][2];
        arr[j][2] = tempColumn[j];
    }
    cout << "\nGot it! Column 1 and Column 3 have been swapped.\n";
}


// ********************************************************
// name:      exitProgram
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The exitProgram function end the program
// ********************************************************
void exitProgram(){
    cout << "Thanks for playing!\n";
}


