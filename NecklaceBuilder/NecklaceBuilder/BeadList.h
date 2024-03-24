/*
 *
 * Celine Wang
 *
 * Specification(Header) file for BeadList class
 *
 * Mar 2024
 *
 */

#ifndef BeadList_h
#define BeadList_h
#include<string>
using namespace std;

class BeadList {
private:
    // Declare a structure for the list
    struct ListNode {
        string bead;            // The value in the node
        struct ListNode* next;   // To point to the next node
    };
    
    ListNode* head;              // head pointer point to the head node
    
public:
    // Constructor
    BeadList()
    {head = nullptr;}
    
    // Destructor
//    ~BeadList();
    
    // Linked list operations
    void appendNode(string);
    void insertNode(string);
    void deleteNode(string);    // "delete" is a reserved keyword
    void displayNode() const;
    void searchNode(string);
};
#endif /* BeadList_h */
