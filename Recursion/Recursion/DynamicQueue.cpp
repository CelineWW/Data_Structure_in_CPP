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
// called by: main
// passed:    string name
// returns:   nothing
// calls:     countBeads
// The appendNode function append a name to the end of    *
// the dynamice queue
// ********************************************************
void DynamicQueue::appendNode(string newName) {
    QueueNode* newNode;
    QueueNode* nodePtr;
    
    // Allocate a new node and store customer name
    newNode = new QueueNode;
    newNode->name = newName;
    newNode->number = getRandomNumber(1, 500);
    newNode->next = nullptr;
    
    // If there are no nodes in the list, make a new one
    if (!head) {
        head = newNode;
    }
    else {     // Otherwise insert newNode at the end
        nodePtr = head;
        // If pointer in next Node is not a nullptr, keep moving forward
        while(nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    cout << "Low: added new node:" << newName << " with number " << newNode->number << endl;
}


// Mutator function definitions
// ********************************************************
// name:      deleteNode
// called by: main
// passed:    int position
// returns:   nothing
// calls:     countBeads
// The deleteNode function delete a node from the head of *
// the dynamic queue
// ********************************************************
void DynamicQueue::deleteNode() {
    // If there are no nodes in the list, display message
    if (!head) {
        cout << "Low: No person in line." << endl;
    }
    // Otherwise,delete first node from the list
    // Make the second node to be the head
    else {
        QueueNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Accessor function definition
// ********************************************************
// name:      countNodes
// called by: int DynamicQueue::numNodes() const
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The countNodes function cumulate the number of nodes   *
// by recursive counting the nodes
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
// called by: int DynamicQueue::ra() const
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The countNodes function cumulate the number of nodes   *
// by recursive counting the nodes
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
        cout << "Random Index:" << randomIndex << endl;
        // Traverse the linked list to find the node correspoding to the random index
        QueueNode* nodePtr = head;
        // Use randomIndex to control steps
        for (int i = 0; i < randomIndex; i++) {
            nodePtr = nodePtr->next;
        }
    }
    return nodePtr->number;
}

// Accessor function definition
// ********************************************************
// name:      getName
// called by: int DynamicQueue::ra() const
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The countNodes function cumulate the number of nodes   *
// by recursive counting the nodes
// ********************************************************
string DynamicQueue::getName(int raffleNumber) {
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



// Accessor function definition
// ********************************************************
// name:      showNode
// called by: int DynamicQueue::ra() const
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The countNodes function cumulate the number of nodes   *
// by recursive counting the nodes
// ********************************************************
void DynamicQueue::showNode(QueueNode* nodePtr) const {
    //
    if (nodePtr) {
        showNode(nodePtr->next);
        cout << "(" << countNodes(nodePtr) - 1 << ")";
        cout << nodePtr->name << " " << nodePtr->number << endl;
    }
}

// Helper function definition
// ********************************************************
// name:      getRandomNumber
// called by: int DynamicQueue::appendNode() const
// passed:    nothing
// returns:   rand(min, max)
// calls:     nobody
// The getRandomNumber function generate a random number  *
// between min and max value
// ********************************************************

static int getRandomNumber(int min, int max) {
    // Get system time
    unsigned seed = static_cast<unsigned int>(time(0));
    
    // Seed the random number generator
    srand(seed);
    
    // Return random nubmer between min and max value
    return (rand() % (max - min + 1) + min);
}
