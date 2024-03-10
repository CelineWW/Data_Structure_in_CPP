/*
 *
 * Celine Wang
 *
 * Chapter 9, Programming 2D Array with pointers
 *
 * Feb 2024
 *
 */


#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

// Global constants
const int SIZE = 16;
const int COLS = 4;

// Function prototyps
void displayMenu();
int getRows(const int, const int);
void displayArray(int*, const int, int);
void getLocation(int*, const int, int);
void swapColumn(int*, const int, int);
void exitProgram();

int main() {
    
    cout << "Array with Pointers Program\n";
    
    // Declare the array caculate the row count
    int myArray[SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
    // Caculate the row count
    int rowCount = getRows(SIZE, COLS);
    // Set the pointer pointing to the first element of the array.
    int* pointer = myArray;
    
    // Prompt user to choose from the menu options
    int choice = 0;
    while(choice != 4) {
        cout << endl;
        displayMenu();          // Display menu
        cout << "\n\nPlease enter your choice: ";
        cin >> choice;
        
        // Data validation for the input
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please re-enter please.\n";
            continue;
        }
        
        // Call function based on user's choice
        switch (choice){
            case 1:
                displayArray(pointer, COLS, rowCount);     // Display 1D integer array into 2D matrix
                break;
            case 2:
                getLocation(pointer, COLS, rowCount);      // Get location for input number
                break;
            case 3:
                swapColumn(pointer, COLS, rowCount);       // Swap column 1 and column 3
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
// name:      getRows
// called by: main
// passed:    const int SIZE, const int COLS
// returns:   int rows
// calls:     nobody
// The getRow function get the ceiling of division result *
// of array size and columns                              *
// ********************************************************

int getRows(const int SIZE, const int COLS){
    int rows = 0;
    // If division reminder is not zero, return true(1), otherwise, return false(0)
    rows = SIZE / COLS + (SIZE % COLS != 0 );
    return rows;
}

// ********************************************************
// name:      displayArray
// called by: main
// passed:    int* ptr, const int COLS, int rows
// returns:   nothing
// calls:     nobody
// The displayArray function split 1D array into 4        *
// columns and display the integer matrix                 *
// ********************************************************

void displayArray(int* ptr, const int COLS, int rows){
    cout << "\nHere is your array:\n";
    // Display single array by 4 * 4 matrix
    for (int i = 0; i < rows; i++ ){
        for (int j = 0; j < COLS; j++){
            cout << right << setw(3) << *(ptr + j + COLS * i) << " ";  // Set numeric output format
        }
        cout << endl;
    }
}

// ********************************************************
// name:      getLocation
// called by: main
// passed:    int* ptr, const int COLS, int rows
// returns:   nothing
// calls:     nobody
// The getLocation function take user's input of a number.*
// Search the number in the array, display a message to   *
// show its location in the matrix                        *
// ********************************************************
void getLocation(int* ptr, const int COLS, int rows){
    int target = 0;
    
    // Create a boolean varialbe for loop control
    bool found = false;
    while (true){
        cout << "Enter an integer to locate: ";
        
        // Valid input - integer
        if (cin >> target) {
            for (int i = 0; i < rows; i++ ){
                for (int j = 0; j < COLS; j++){
                    
                    // If integer is found in the array
                    if (*(ptr + j + COLS * i) == target) {
                        cout << target << " is located on row " << i + 1 << ", cloumn " << j + 1 << ".\n";
                        found = true;
                        break;
                    }
                }
            }
            
            // If input is a valid integer, but not found in the array.
            if (found == false) {
                cout << target << " is not found in the array.\n";
            }
            break;
        }
        // Invalid input - Not an integer
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
// passed:    int* ptr, const int COLS, int rows
// returns:   nothing
// calls:     nobody
// The swapColumn function swap the cloumn 1 and cloumn 3 *
// in the "split array" and save the changes.             *
// ********************************************************
void swapColumn(int* ptr, const int COLS, int rows){
    int temp = 0;
    for (int i = 0; i < rows; i++){
        temp = *(ptr + COLS * i);                    // Temporarily save the 1st value in each row in [temp].
        *(ptr + COLS * i) = *(ptr + 2 + COLS * i);   // Assign 3rd number value to 1st number in each row
        *(ptr + 2 + COLS * i) = temp;                // Assign temporaily saved [temp] value to 3rd number in each row
    }
    cout << "\nGot it! Column 1 and Column 3 have been swapped.\n";
}


// ********************************************************
// name:      exitProgram
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The exitProgram function end the program               *
// ********************************************************
void exitProgram(){
    cout << "Thanks for playing!\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


