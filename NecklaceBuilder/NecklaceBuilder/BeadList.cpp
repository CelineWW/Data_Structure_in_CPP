/*
 *
 * Celine Wang
 *
 * Implementation file for BeadList class
 *
 * Mar 2024
 *
 */

#include "BeadList.h"
#include <iostream>
#include <string>

using namespace std;

// Accessor function definitions
// ********************************************************
// name:      displayNode
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayNode function travesrse the beads of the    *
// necklace
// ********************************************************
void BeadList::displayNode() const{
    ListNode* nodePtr;      // To move through the list
    
    // Position nodePtr at the head of the necklace
    nodePtr = head;
    int index = 0;
    
    // while nodePtr points to a node (not nullptr), traverse the list
    while (nodePtr) {
        // Display the bead and its index in this node
        cout << "(" << index << ") " << nodePtr->bead << endl;
        // Move to the next node
        nodePtr = nodePtr->next;
    }
}


// Mutator function definitions
// ********************************************************
// name:      appendNode
// called by: main
// passed:    string metal
// returns:   nothing
// calls:     nobody
// The appendNode function append the bead to the end of  *
// the necklace
// ********************************************************
void BeadList::appendNode(string metal) {
    ListNode* newNode;      // To point to a new node
    ListNode* nodePtr;      // To move through the list
    
    // Allocate a new node and store bead
    newNode = new ListNode;
    newNode->bead = metal;
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
}

