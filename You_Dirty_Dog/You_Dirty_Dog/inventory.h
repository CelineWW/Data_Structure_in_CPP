/*
 *
 * Celine Wang
 *
 * Specification(Header) file for the dog Inventory class
 *
 * Mar 2024
 *
 */

#ifndef Inventory_h
#define Inventory_h
#include <string>
using namespace std;

class Inventory{
private:
    string dogLicense;
    string dogName;
    string ownerPhone;
    float priceQuoted;
public:
    // Default constructor
    Inventory();
    // Overloading constructor
    Inventory(string, string, string, float);
//        Inventory(){
//            dogLicense = "";
//            dogName = "";
//            ownerPhone = "";
//            priceQuoted = 0.0;
//        };
//        
//        // Constructor2 take arguements
//        Inventory(string dogLicense_p, string dogName_p, string ownerPhone_p, float priceQuoted_p){
//            dogLicense = dogLicense_p;
//            dogName = dogName_p;
//            ownerPhone = ownerPhone_p;
//            priceQuoted = priceQuoted_p;
//        };
    
    // Mutator function declarations
    void setDogLicense(string);
    void setDogName(string);
    void setOwnerPhone(string);
    void setPriceQuoted(float);
    
    // Accessor inline functions
    string getDogLicense() const { return dogLicense;}
    string getDogName() const { return dogName;}
    string getOwnerPhone() const { return ownerPhone;}
    float getPriceQuoted() const { return priceQuoted;}
};
#endif /* Inventory_h */
