/*
 *
 * Celine Wang
 *
 * Chapter 13, Programming You Dirty Dog with a dog inventory class
 *
 * Mar 2024
 *
 */

#include <iostream>
#include <iomanip>
#include "Inventory.h"
using namespace std;

// Function declarations
void displayMenu();
void addJob(Inventory (&)[], int);
void addDogLicense(Inventory &);
void addDogName(Inventory &);
void addOwnerPhone(Inventory &);
void addPriceQuoted(Inventory &);
void listJobs(const Inventory (&)[], int);
void exitProgram();

// Global constant variable to hold maximum inventory
const int NUM_DOGS = 5;

int main() {
    cout << "Dog Inventory Program\n";
    cout << "This program keep track of dog bathing business.\n";
    
    // Create an array to hold dirty dogs inventory (5 in maximum)
    Inventory dirtyDogs[NUM_DOGS] = {
        Inventory(),
        Inventory(),
        Inventory(),
        Inventory(),
        Inventory()
    };
    
    int choice = 0;
    while(choice != 3) {
        displayMenu();
        cout << "Enter menu choice: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Choose a number from the menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1:
                addJob(dirtyDogs, NUM_DOGS);
                break;
            case 2:
                listJobs(dirtyDogs, NUM_DOGS);
                break;
            case 3:
                exitProgram();
                break;
            default:
                cout << "Invalid enter! Choose an option between 1-3.\n";
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
// The displayMenu function display the menu of dirty     *
// dog inventory business                                 *
// ********************************************************
void displayMenu() {
    cout << "\nYou Dirty Dog Menu\n";
    cout << "1. Enter a new job\n";
    cout << "2. List all current jobs\n";
    cout << "3. Exit\n\n";
}




// ********************************************************
// name:      addJob
// called by: main
// passed:    Inventory (&dirtyDogs_p)[], const int NUM_DOGS
// returns:   nothing
// calls:     nothing
// The addJob function taking input to add inventory of   *
// dirty dog business                                     *
// ********************************************************
void addJob(Inventory (&dirtyDogs_p)[], int size) {
    for (int i = 0; i < size; i++) {
        if (dirtyDogs_p[i].getDogLicense() == "") {
            addDogLicense(dirtyDogs_p[i]);
            addDogName(dirtyDogs_p[i]);
            addOwnerPhone(dirtyDogs_p[i]);
            addPriceQuoted(dirtyDogs_p[i]);
            cout << "Thank you, we will take good care of " << dirtyDogs_p[i].getDogName() << " today!\n";
            break;
        }
    }
    if (dirtyDogs_p[size - 1].getDogLicense()  != "") {
        cout << "Sorry! Our current inventory is full.\n";
        cout << "Please come to visit us another day.\n";
    }
}


// ********************************************************
// name:      addDogLicense
// called by: addJob
// passed:    void
// returns:   nothing
// calls:     nobody
// The addDogLicense function validate user's input of    *
// License Number, then assign to inventory dogLicense    *
// memeber                                                *
// ********************************************************
void addDogLicense(Inventory &dirtyDog) {
    string dogLicense_temp = "";
    cout << "\nDog License Number: ";
    cin >> dogLicense_temp;
    cin.ignore();
    while(dogLicense_temp.length() >= 10) {
        cout << "Sorry, License Number is too long. \n";
        cout << "Enter a License Number less than 10 charactors.\n";
        cout << "Dog License Number: ";
        cin >> dogLicense_temp;
        cin.ignore();
    }
    dirtyDog.setDogLicense(dogLicense_temp);
}


// ********************************************************
// name:      addDogName
// called by: addJob
// passed:    void
// returns:   nothing
// calls:     nobody
// The addDogName function validate user's input of       *
// Dog Name, then assign to inventory dogName   memeber   *
// ********************************************************
void addDogName(Inventory &dirtyDog) {
    string dogName_temp = "";
    cout << "Dog Name: ";
    getline(cin, dogName_temp);
//    cin.ignore();
    while(dogName_temp.length() >= 15) {
        cout << "Sorry, Dog Name is too long. \n";
        cout << "Enter a Dog Name less than 15 charactors.\n";
        cout << "Dog Name: ";
        getline(cin, dogName_temp);
        cin.ignore();
    }
    dirtyDog.setDogName(dogName_temp);
}

// ********************************************************
// name:      addOwnerPhone
// called by: addJob
// passed:    void
// returns:   nothing
// calls:     nobody
// The addOwnerPhone function validate user's input of    *
// Owner Phone, then assign to inventory object           *
// ********************************************************
void addOwnerPhone(Inventory &dirtyDog) {
    string dogOwnerPhone_temp = "";
    long dogOwnerPhone_digit = 0;
    bool valid_type = false;
    bool valid_range = false;
    while (!valid_type || !valid_range) {
        cout << "Customer Phone: ";
        cin >> dogOwnerPhone_temp;
        cin.ignore();
        
        // Validate the phone nubmer to be all digits
        while (!all_of(dogOwnerPhone_temp.begin(), dogOwnerPhone_temp.end(), ::isdigit)) {
            valid_type = false;
            cout << "Phone number must be all digits.\n";
            cout << "Customer Phone: ";
            cin >> dogOwnerPhone_temp;
            cin.ignore();
        }
        dogOwnerPhone_digit = stol(dogOwnerPhone_temp);
        valid_type = true;
        
        // Validate the phone nubmer to be less than 11 digits
        if (dogOwnerPhone_digit < 9999999999 && dogOwnerPhone_digit > 0) {
            valid_range = true;
        }
        else {
            valid_range = false;
            cout << "Sorry, Invalid Number!\n";
            cout << "Enter a Customer Phone Number less than 11 digits.\n";
        }
        // Validate the phone nubmer to be less than 11 digits
//        while(dogOwnerPhone_digit > 9999999999 || dogOwnerPhone_digit < 0) {
//            valid_range = false;
//            cout << "Sorry, Invalid Number!\n";
//            cout << "Enter a Customer Phone Number less than 11 digits.\n";
//            cout << "Customer Phone: ";
//            cin >> dogOwnerPhone_temp;
//            cin.ignore();
//        }
    }
    dirtyDog.setOwnerPhone(dogOwnerPhone_temp);
}


// ********************************************************
// name:      addPriceQuoted
// called by: addJob
// passed:    void
// returns:   nothing
// calls:     nobody
// The addPrice function validate user's input of         *
// Price, then assign to inventory priceQuoted member     *
// ********************************************************
void addPriceQuoted(Inventory &dirtyDog) {
    string priceQuoted_string = "";
    float priceQuoted_temp = 0.0;
    int currency_index = 0;
    bool valid_format = true;
    do {
        cout << "Price: ";
        cin >> priceQuoted_string;
        cin.ignore();
        // Searach for '$' in reverse order
        currency_index = static_cast<int>(priceQuoted_string.rfind('$'));
        // '$' must be the first charactor[0] or not exist[-1]
        if (currency_index > 0 || currency_index < -1) {
            valid_format = false;
            cout << "'$' must be the first charactor if exists.\n";
            continue;
        }
        
        // Searach for and count '.' in the input string
        int dot_index = 0;
        int dot_count = 0;
        for (char c : priceQuoted_string) {
            if (c == '.') {
                dot_count++;
            }
        }
        // Multiple '.' is not accepted
        if (dot_count > 1) {
            valid_format = false;
            cout << "Multiple decimal points used.\n";
        }
        
        // Input string does not contain dot, then the rest of charactors must be all digits or '$'
        else if (dot_count == 0) {
            for (char c : priceQuoted_string) {
                if (c != '$' && !isdigit(c)) {
                    valid_format = false;
                    cout << "Invalid Price. Re-Enter Please!\n";
                    break;
                }
                else {
                    valid_format = true;
                }
            }
        }
        
        // Input string contains exactly 1 dot, then the rest of charactors must be all digits or '$'
        else if (dot_count == 1) {
            dot_index = static_cast<int>(priceQuoted_string.find('.'));
            for (char c : priceQuoted_string) {
                if (c != '$' && c != '.' && !isdigit(c)) {
                    valid_format = false;
                    cout << "Invalid Price. Re-Enter Please!\n";
                    break;
                }
                else {
                    valid_format = true;
                }
            }
        }
        if (valid_format) {
            break;
        }
    } while (!valid_format) ;
    
    // User input contains a '$'
    if (currency_index > -1) {
        priceQuoted_temp = stof(priceQuoted_string.substr(1));
    }
    // User input only contains digits with or without decimal points
    if (currency_index < 0) {
        priceQuoted_temp = stof(priceQuoted_string);
    }
    dirtyDog.setPriceQuoted(priceQuoted_temp);
}



// ********************************************************
// name:      listJobs
// called by: main
// passed:    const Inventory (&dirtyDogs_p)[], const int NUM_DOGS
// returns:   nothing
// calls:     nobody
// The listJobs function display the current jobs of      *
// dirty dog bathing tasks                                *
// ********************************************************
void listJobs(const Inventory (&dirtyDogs_p)[], int size) {
    int inventoryCount = 0;
    float totalPrice = 0.0;
    cout << fixed << setprecision(2);
    cout << "\nCurrent Jobs:\n";
    
    cout << left << setw(20) << "Dog License" << setw(20) << "Dog License"
        << setw(20) << "Owner Phone" <<  setw(15) << "Price Quoted" << endl;
    cout << left << setw(20) << "===========" << setw(20) << "==========="
        << setw(20) << "===========" <<  setw(15) << "============" << endl;
    // print non-default dirty dog inventory
    for (int i = 0 ; i < size; i++) {
        if (dirtyDogs_p[i].getDogLicense() != "") {
            cout << setw(20) <<dirtyDogs_p[i].getDogLicense();
            cout << setw(20) <<dirtyDogs_p[i].getDogName();
            cout << setw(20) <<dirtyDogs_p[i].getOwnerPhone();
            cout << "$" << setw(15) << dirtyDogs_p[i].getPriceQuoted() << endl;
            
            // Increment inventory count and total price.
            inventoryCount ++;
            totalPrice += dirtyDogs_p[i].getPriceQuoted();
        }
    }
    cout << "------------------------------------------------\n";
    cout << "You currently have " << inventoryCount << " jobs with a total of $" << totalPrice << ".\n\n";
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
    cout << "Thanks for using the menu system and hava a nice day.\n";
    cout << "-----------------------------------------------------\n";
}
