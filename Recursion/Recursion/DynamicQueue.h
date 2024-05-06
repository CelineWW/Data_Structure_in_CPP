/*
 *
 * Celine Wang
 *
 * Specification(Header) file for DynamicQueue class
 * of Chapter 20, Programming Recursion
 *
 * Apr 2024
 *
 */
#include <string>
using namespace std;

#ifndef DynamicQueue_h
#define DynamicQueue_h
class DynamicQueue {
private:
    // Decalre a structure for the list
    struct QueueNode {
        string name;
        int number;
        struct QueueNode* next;
    };

    // Linked list head pointer
    QueueNode* head;
    
    // Private member function
    int countNodes(QueueNode*) const;
    int pickNode(QueueNode*) const;
    void showNode(QueueNode*) const;
    
    
public:
    // Constructor
    DynamicQueue() { head = nullptr; }
    
    // Destructor
    ~DynamicQueue();
    
    // Linked list operations
    int appendNode(string);         // Mutator
    string deleteNode();            // Mutator
    int numNodes() const { return countNodes(head); }         // Accessor
    int raffleTicket() const { return pickNode(head); }       // Accessor
    void displayList() const { showNode(head); };             // Accessor
    
    // Helper functions
    static int getRandomNumber(int, int);
    string getName(int) const;
};
#endif /* DynamicQueue_h */
