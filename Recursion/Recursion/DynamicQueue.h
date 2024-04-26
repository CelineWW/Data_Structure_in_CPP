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

    // Linked list front and real pointer
    QueueNode* front;
    QueueNode* real;
    
    // Private member function
    int countNodes(QueueNode*) const;
    int pickNode(QueueNode*) const;
    void showNode(QueueNode*) const;
    
    
public:
    // Constructor
    DynamicQueue() { front = nullptr; real = nullptr; }
    
    // Destructor
    ~DynamicQueue();
    
    // Linked list operations
    int appendNode(string);         // Mutator
    string deleteNode();            // Mutator
    int numNodes() const { return countNodes(front); }         // Accessor
    int raffleTicket() const { return pickNode(front); }       // Accessor
    void displayList() const { showNode(front); };             // Accessor
    
    // Helper functions
    static int getRandomNumber(int, int);
    string getName(int) const;
};
#endif /* DynamicQueue_h */
