/*
 *
 * Celine Wang
 *
 * Implementation file for BeadList class 
 * of Chapter 18, Programming NecklaceBuilder
 *
 * Mar 2024
 *
 */

#include "BeadList.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


// Class member definition
const string BeadList::colors[4] = {"turquoise", "coral", "gold", "copper"};

/*
 Low level validation of Mutator Function
 appendNode: bead - in colors array;
 insertNode: bead - in colors array,  0 <= position <= beadsCount;
 deleteNode: 0 <= postion < beadsCount.
 */


// Mutator function definitions
// ********************************************************
// name:      appendNode
// called by: main
// passed:    string color
// returns:   nothing
// calls:     countBeads
// The appendNode function append a bead to the end of    *
// the necklace
// ********************************************************
void BeadList::appendNode(string color) {
    // Exit_failure while material is not allowed
    if(!colorCheck(color)){
        cout << "Error: " << color << " is not a metal that we carry.\n";
        exit(EXIT_FAILURE);
    }
    ListNode* newNode;      // To point to a new node
    ListNode* nodePtr;      // To move through the list
    
    // Allocate a new node and store bead
    newNode = new ListNode;
    newNode->bead = color;
    newNode->next = nullptr;
    
    // If there are no nodes in the list, make a new one
    if (!head) {
        head = newNode;
    }
    else {          // Otherwise insert newNode at the end
        nodePtr = head;
        // If pointer in next Node is not a nullptr, keep moving forward
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        // Now nodePtr is pointing to the last node
        // Change the pointer in last node point to the new node
        nodePtr->next = newNode;
    }
    
    // Display append output message
    cout << "Thank you - a ";
    cout << color << " bead has been added to your necklace at position ";
    cout << countBeads() - 1 << endl;
}


// Mutator function definitions
// ********************************************************
// name:      insertNode
// called by: main
// passed:    string color, int position
// returns:   nothing
// calls:     countBeads
// The insertNode function insert a bead to a desired     *
// location of the necklace
// ********************************************************
void BeadList::insertNode(string color, int position) {
    // Check if position is valid comparing to necklace length
    int beadsCount = countBeads();
    
    // Exit_failure while material is not allowed
    if(!colorCheck(color)){
        cout << "Error: " << color << " is not a metal that we carry.\n";
        exit(EXIT_FAILURE);
    }
    
    // Position must be between 0 and beadsCount
    if (position < 0 || position > beadsCount) {
        cout << "Sorry, the position is out of range.\n";
        return;
    }
    
    // If position is valid
    else {
        ListNode* newNode;      // To point to a new node
        ListNode* nodePtr;      // To move through the list
        ListNode* previousNode = nullptr;  // To point to previous node and initialize to nullptr
        
        // Allocate a new node and store bead
        newNode = new ListNode;
        newNode->bead = color;
        newNode->next = nullptr;
       
        
        // If no bead in the list, add new node the first one
        if (!head) {
            head = newNode;
            newNode->next = nullptr;
        }
        
        // If the list is not empty, but position is 0, make new node the first one
        else if (head && position == 0) {
//            cout << head->bead;
            newNode->next = head;
            head = newNode;
        }
        
        else {          // Otherwise insert newNode at the right position
            int index = 0;
            
            // Position nodePtr at the head of list
            nodePtr = head;
            
            // If pointer in next Node is not a nullptr, keep moving forward
            while (nodePtr != nullptr && index < position) {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
                ++index;
            }
            
            // Insert new node after the previous node
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
        // Insert output message
        cout << "Than you - a ";
        cout << color << " bead has been inserted at position ";
        cout << position << endl;
    }
}


// Mutator function definitions
// ********************************************************
// name:      deleteNode
// called by: main
// passed:    int position
// returns:   nothing
// calls:     countBeads
// The deleteNode function delete a bead to a desired     *
// location of the necklace
// ********************************************************
void BeadList::deleteNode(int position) {
    // Check if position is valid comparing to necklace length
    int beadsCount = countBeads();
    
    // Position must be between 0 and beadsCount
    if (position < 0 || position >= beadsCount) {
        cout << "I'm sorry but bead position " << position << " does not exist.\n";
        return;
    }
    // If position is valid
    else {
        ListNode* nodePtr;      // To move through the list
        ListNode* previousNode = nullptr;  // To point to previous node and initialize to nullptr
        
        // If no bead in the list, do nothing
        if (!head) {
            return;
        }
        
        // If the list is not empty, but position is 0
        else if (head && position == 0) {
            nodePtr = head->next;    // nodePtr points to the second node
            delete head;
            head = nodePtr;          // now nodePtr points to the first node
        }
        
        else {          // Otherwise delete the Node at the right position
            int index = 0;
            
            // Position nodePtr to the head of list
            nodePtr = head;
            
            // If pointer in next Node is not a nullptr, keep moving forward
            while (nodePtr != nullptr && index < position) {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
                ++index;
            }
            
            // delete the node after the previous node
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
    cout << "Node (" << position << ") has been deleted from your list.\n";
}

// Accessor function definition
// ********************************************************
// name:      displayNode
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayNode function travesrse the beads of the    *
// necklace
// ********************************************************
void BeadList::displayNode() const {
    ListNode* nodePtr;      // To move through the list
    
    // Position nodePtr at the head of the necklace
    nodePtr = head;
    int index = 0;
    if (!head) {
        cout << "No beads in your necklace.\n";
    }
    else {
        cout << "Here is your current list:\n";
        // while nodePtr points to a node (not nullptr), traverse the list
        while (nodePtr) {
            // Display the bead and its index in this node
            cout << "(" << index << ") " << nodePtr->bead << endl;
            // Move to the next node
            nodePtr = nodePtr->next;
            ++index;
        }
    }
    cout << endl;
}


// Accessor function definitions
// ********************************************************
// name:      searchNode
// called by: main
// passed:    string color
// returns:   int
// calls:     nobody
// The searchNode function take the user input of bead    *
// color, then return the location in the necklace
// ********************************************************
vector<int> BeadList::searchNode(string color) const {
    vector<int> position;   // Hold an array of index that the color found
    cout << "Looking for " << color << " beads:\n";
    // If the color is valid
    if(colorCheck(color)){
        ListNode* nodePtr;      // To move through the list
        // Position nodePtr at the head of the necklace
        nodePtr = head;
        int index = 0;
        
        // While nodePtr points to next node, traverse the list, not including the last bead
        while (nodePtr->next) {
            // If color found, append to the position vector
            if (nodePtr->bead == color) {
                position.push_back(index);
            }
            // Move to the next node
            nodePtr = nodePtr->next;
            ++index;
        }
        
        // Check the last node
        if (!nodePtr->next) {
            if (nodePtr->bead == color) {
                position.push_back(index);
            }
        }
        
        // If no beads found from the entire list
        if (position.size() == 0) {
            position.push_back(-1);
        }
        return position;
    }
    // Else if the color is not valid
    else {
        position.push_back(-1);
        return position;
    }
}



// Accessor function definitions
// ********************************************************
// name:      countBeads
// called by: insertNode, deleteNode,searchNode
// passed:    nothing
// returns:   int
// calls:     nobody
// The countBeads function count beads of the necklace    *
// ********************************************************
int BeadList::countBeads() const{
    int beadsCount = 0;      // Count bead
    ListNode* nodePtr;      // To move through the list
    
    // Position nodePtr at the head of the necklace
    nodePtr = head;
    
    // while nodePtr points to a node (not nullptr), stop counting
    while (nodePtr) {
        // Display the bead and its index in this node
        ++beadsCount;
        // Move to the next node
        nodePtr = nodePtr->next;
    }
    return beadsCount;
}


// Accessor function definitions
// ********************************************************
// name:      colorCheck
// called by: insertNode, searchNode
// passed:    sting color
// returns:   bool
// calls:     nobody
// The colorCheck function check if the color is valid    *
// ********************************************************
bool BeadList::colorCheck(string color) const {
    bool validColor = false;
    
    // Covert color input to all lower case
    for (char &c : color) {
        c = tolower(c);
    }
    
    if (find(begin(colors), end(colors), color) == end(colors) ) {
        validColor = false;
    }
    else {
        validColor = true;
    }
    return validColor;
}


// Destructor definitions
// ********************************************************
// name:      ~BeadList
// called by: main
// passed:
// returns:   nothing
// calls:     nobody
// The ~BeadList function destroy the bead list after     *
// delete all nodes
// ********************************************************
BeadList::~BeadList() {
    ListNode* nodePtr;     // To point to a new node
    ListNode* nextNode;    // To point to next node
    
    // Position nodePtr at the head of the list
    nodePtr = head;
    
    // While nodePtr is not at the end of the list
    while(nodePtr != nullptr) {
        nextNode = nodePtr->next;
        
        // Delete the current node
        delete nodePtr;
        
        // Position nodePtr at next node
        nodePtr = nextNode;
    }
}
