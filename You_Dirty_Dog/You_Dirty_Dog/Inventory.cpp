/*
 *
 * Celine Wang
 *
 * Implementation file for the dog Inventory class
 *
 * Mar 2024
 *
 */

#include "Inventory.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Default constructor with all variable initialized
Inventory::Inventory(){
    dogLicense = "";
    dogName = "";
    ownerPhone = "";
    priceQuoted = 0.0;
};

// Constructor2 take arguements
Inventory::Inventory(string dogLicense_p, string dogName_p, string ownerPhone_p, float priceQuoted_p) {
    dogLicense = dogLicense_p;
    dogName = dogName_p;
    ownerPhone = ownerPhone_p;
    priceQuoted = priceQuoted_p;
};

// Mutator function definitions
// ********************************************************
// name:      setDogLicense
// called by: Inventory object
// passed:    string dogLicense_p
// returns:   nothing
// calls:     nobody
// The setDogLicense function assign the value of         *
// dogLicense private member                              *
// ********************************************************
void Inventory::setDogLicense(string dogLicense_p) {
    if (dogLicense_p.length() >= 10) {
        cout << "Dog license must be less than 10 charactors.\n";
        exit(EXIT_FAILURE);
    }
    else {
        dogLicense = dogLicense_p;
    }
};

// ********************************************************
// name:      setDogName
// called by: Inventory object
// passed:    string dogName_p
// returns:   nothing
// calls:     nobody
// The setDogName function assign the value of            *
// dogName private member                                 *
// ********************************************************
void Inventory::setDogName(string dogName_p) {
    if (dogName_p.length() >= 15) {
        cout << "Dog Name must be less than 15 charactors.\n";
        exit(EXIT_FAILURE);
    }
    else {
        dogName = dogName_p;
    }
};

// ********************************************************
// name:      setOwnerPhone
// called by: Inventory object
// passed:    string ownerPhone_p
// returns:   nothing
// calls:     nobody
// The setOwnerPhone function assign the value of         *
// ownerPhone private member                              *
// ********************************************************
void Inventory::setOwnerPhone(string ownerPhone_p) {
    if (ownerPhone_p.length() >= 11) {
        cout << "Customer phone number must be less than 11 digits.\n";
        exit(EXIT_FAILURE);
    }
    else {
        ownerPhone = ownerPhone_p;
    }
};

// ********************************************************
// name:      setPriceQuoted
// called by: Inventory object
// passed:    string priceQuoted_p
// returns:   nothing
// calls:     nobody
// The setPriceQuoted function assign the value of        *
// priceQuoted private member                              *
// ********************************************************
void Inventory::setPriceQuoted(float priceQuoted_p) {
    if (priceQuoted_p < 0) {
        cout << "Quoted price must be non-negative.\n";
        exit(EXIT_FAILURE);
    }
    else {
        priceQuoted = priceQuoted_p;
    }
};
