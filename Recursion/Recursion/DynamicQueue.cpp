/*
 *
 * Celine Wang
 *
 * Implementation file for DynamicQueue class
 * of Chapter 20, Programming Recursion
 *
 * Apr 2024
 *
 */
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "DynamicQueue.h"
//using namespace std;

// Destructor Definition
// ********************************************************
// name:      ~DynamicQueue
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nothing
// The ~DynamicQueue function deletes every node in the   *
// linked list of DynamicQueue                            *
// ********************************************************
DynamicQueue::~DynamicQueue() {
    QueueNode* nodePtr = nullptr;
    QueueNode* nextNode = nullptr;
    
    // Position nodePtr at the head of the list
    nodePtr = head;
    
    // Traverse the list deleting each node
    while (nodePtr) {          // If nodePtr is not nullptr
        nextNode = nodePtr->next;
        delete nodePtr;        // Delete current node
        nodePtr = nextNode;    // Move pointer to next node
    }
}

// Mutator function definitions
// ********************************************************
// name:      appendNode
// called by: void addName(DynamicQueue&)
// passed:    string
// returns:   int
// calls:     static int getRandomNumber(int, int)
// The appendNode function append a node(to the rear of   *
// the dynamice queue, return a random number that
// assigned to this new node
// ********************************************************
int DynamicQueue::appendNode(string newName) {
    if (newName.size() >= 20) {
        cout << "Low: Name is too long." << endl;
        return -1;
    }
    else {
        int numberAssigned;
        QueueNode* newNode;
        QueueNode* nodePtr;
        
        // Allocate a new node and store customer name
        // Assign this new customer a random ticket number between 1 to 500
        newNode = new QueueNode;
        newNode->name = newName;
        newNode->number = getRandomNumber(1, 500);
        newNode->next = nullptr;
        
        // If there are no nodes in the list, make a new one
        if (!head) {
            head = newNode;
        }
        else {     // Otherwise insert newNode in the end
            nodePtr = head;
            newNode->next = nodePtr;
            head = newNode;
        }
        numberAssigned = newNode->number;
        return numberAssigned;
    }
}


// Mutator function definitions
// ********************************************************
// name:      deleteNode
// called by: void makeOrder(DynamicQueue&);
// passed:    nothing
// returns:   string
// calls:     nothing
// The deleteNode function delete a node from the head of *
// the dynamic queue
// ********************************************************
string DynamicQueue::deleteNode() {
    string customer;
    // If there are no nodes in the list, display message
    if (!head) {
        cout << "No person in line." << endl;
    }
    // Otherwise,delete last node from the list
    // Make the second last node to be the end
    else {
        QueueNode* nodePtr = head;
        QueueNode* previousPtr = nullptr;
        
        // Traverse the list to reach the last node
        while (nodePtr->next) {
            previousPtr = nodePtr;
            nodePtr = nodePtr->next;
            customer = nodePtr->name;
        }
        
        // nodePtr is the last node, previousPtr is the second last node
        if (previousPtr) {          // Multiple node in the list
            previousPtr->next = nullptr;
        }
        else {                      // Only one node in the list
            head = nullptr;
        }
        delete nodePtr;
    }
    return customer;
}

// Accessor function definition
// ********************************************************
// name:      countNodes
// called by: int DynamicQueue::numNodes() const
// passed:    QueueNode*
// returns:   int
// calls:     countNodes(QueueNode* nodePtr) - recursive
// The countNodes function cummulate the number of nodes  *
// by recursively counting the nodes                      *
// ********************************************************
int DynamicQueue::countNodes(QueueNode* nodePtr) const {
    // While has a value, add 1 to the count
    if (nodePtr) {
        return 1 + countNodes(nodePtr->next);
    }
    else {
        return 0;
    }
}

// Accessor function definition
// ********************************************************
// name:      pickNode
// called by: int DynamicQueue::raffleTicket() const
// passed:    QueueNode*
// returns:   int
// calls:     static int getRandomNumber(int, int)
// The pickNode function randomly pick a node from the    *
// current queue
// ********************************************************
int DynamicQueue::pickNode(QueueNode* nodePtr) const {
    // Count the number of nodes
    int nodeCount = countNodes(head);
    
    // If no nodes exits, return -1
    if (nodeCount == 0) {
        return -1;
    }
    // Otherwise get a random index from assigned tickets
    else {
        int randomIndex = getRandomNumber(1, nodeCount);
        // Use randomIndex to control steps
        for (int i = 0; i < randomIndex; i++) {
            nodePtr = nodePtr->next;
        }
    }
    // return raffle ticket number
    return nodePtr->number;
}


// Accessor function definition
// ********************************************************
// name:      showNode
// called by: void displayList() const
// passed:    QueueNode*
// returns:   nothing
// calls:     void showNode(QueueNode*) const
//            int countNodes(QueueNode*) const
// The showNode function traverse the list to show each   *
// name and ticket number stored in nodes
// ********************************************************
void DynamicQueue::showNode(QueueNode* nodePtr) const {
    if (nodePtr) {
        showNode(nodePtr->next);
        cout << "(" << countNodes(nodePtr) - 1 << ") ";
        cout << fixed << setw(20) << left << nodePtr->name << " " << nodePtr->number << endl;
    }
}

// Helper function definition
// ********************************************************
// name:      getRandomNumber
// called by: int DynamicQueue::appendNode() const
//            int pickNode(QueueNode*) const
// passed:    nothing
// returns:   int
// calls:     nobody
// The getRandomNumber function generate a random number  *
// between min and max value
// ********************************************************
int DynamicQueue::getRandomNumber(int min, int max) {
    // Get system time
    unsigned seed = static_cast<unsigned int>(time(0));
    
    // Seed the random number generator
    srand(seed);
    
    // Return random nubmer between min and max value
    return (rand() % (max - min + 1) + min);
}

// Helper function definition
// ********************************************************
// name:      getName
// called by: int DynamicQueue::ra() const
// passed:    nothing
// returns:   string
// calls:     int numNodes() const
// The getName function search node from current queue to *
// get name of customer based on the ticket number
// ********************************************************
string DynamicQueue::getName(int raffleNumber) const{
    int nodeCount = numNodes();
    string raffleName;
    
    // Traverse the queue to find the name corresponding to the raffle number
    QueueNode* nodePtr = head;
    for (int i = 0; i < nodeCount; i++) {
        if (nodePtr->number == raffleNumber) {
            raffleName = nodePtr->name;
            break;
        }
        else {
            nodePtr = nodePtr->next;
        }
    }
    return raffleName;
}
