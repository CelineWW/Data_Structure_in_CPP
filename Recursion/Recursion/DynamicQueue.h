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
    int appendNode(string);
    string deleteNode();
    int numNodes() const { return countNodes(head); }
    int raffleTicket() const { return pickNode(head); }
    string getName(int) const;
    void displayList() const { showNode(head); };
    static int getRandomNumber(int, int);
};
#endif /* DynamicQueue_h */
