/*
 *
 * Celine Wang
 *
 * Specification(Header) file for BeadList class
 * of Chapter 18 Programming NecklaceBuilder
 *
 * Mar 2024
 *
 */

#ifndef BeadList_h
#define BeadList_h
#include<string>
#include<vector>
using namespace std;

class BeadList {
private:
    // Declare a structure for the list
    struct ListNode {
        string bead;            // The value in the node
        struct ListNode* next;   // To point to the next node
    };
    
    ListNode* head;              // Head pointer point to the head node
    const static string colors[4];     // To hold bead color options
    
public:
    // Constructor
    BeadList()
    {head = nullptr;}
    
    // Destructor
    ~BeadList();
        
    // Linked list operations
    void appendNode(string);                  // Mutator - Low level validation in colors (exit)
    void insertNode(string, int);             // Mutator - Low level validation in colors (exit) and position (-1)
    void deleteNode(int);                     // Mutator - Low level validation in position (-1)
    void displayNode() const;                 // Accessor
    vector<int> searchNode(string) const;     // Accessor
    int countBeads() const;                   // Help Function
    bool colorCheck(string) const;            // Help Function
};

#endif /* BeadList_h */

