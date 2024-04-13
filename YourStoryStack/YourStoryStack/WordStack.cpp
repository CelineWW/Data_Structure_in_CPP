/*
 *
 * Celine Wang
 *
 * Implementation file for WordStack class
 * of Chapter 19, Programming Your Story Stack
 *
 * Apr 2024
 *
 */

#include "WordStack.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Destructor Definition
// ********************************************************
// name:      ~WordStack
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nothing
// The ~WordStack function deletes every node in the list *
// ********************************************************
WordStack::~WordStack() {
    StackNode* nodePtr = nullptr;
    StackNode* nextNode = nullptr;
    
    // Position nodePtr at the top of the stack
    nodePtr = top;
    
    // Traverse the list deleting each node
    while (nodePtr) {          // If nodePtr is not nullptr
        nextNode = nodePtr->next;
        delete nodePtr;        // Delete current node
        nodePtr = nextNode;    // Move pointer to next node
    }
}

// Member Function Definition
// ********************************************************
// name:      push
// called by: main
// passed:    string word
// returns:   nothing
// calls:     nothing
// The push function push the arguemnt onto the stack     *
// ********************************************************
void WordStack::push(string word) {
    bool validWord = true;
    // Low level validation of word length
    if (word.empty()) {
        cout << "Error: The word cannot be blank.\n";
        exit(EXIT_FAILURE);
    }
    else if (word.size() < 1 || word.size() > 10) {
        cout << "Error: Word legnth must be between 1 and 10.\n";
        exit(EXIT_FAILURE);
    }
    else {     // Word length satisfied: 1-10 characters
        // Low level validation of letters in word
        for (char c : word) {
            if (!isalpha(c)) {
                cout << "Error: The character in word must be all letters.\n";
                validWord = false;
                exit(EXIT_FAILURE);
            }
        }
    }
    if (validWord) {
        StackNode* newNode = nullptr;    // Point to a new node
        
        // Allocate a new node and store word there
        newNode = new StackNode;
        newNode->value = word;
        
        // If the list is empty, make newNode the first node
        if (isEmpty()) {
            top = newNode;
            newNode->next = nullptr;
        }
        else {  // Otherwise, insert newNode befor  top
            newNode->next = top;
            top = newNode;
        }
    }
}


// Member Function Definition
// ********************************************************
// name:      pop
// called by: main
// passed:    string &word
// returns:   nothing
// calls:     isEmpty
// The pop function pops the value at the top of the stack*
// off, and copies it into the variable passed as an      *
// argument
// ********************************************************
void WordStack::pop(string &word) {
    if (isEmpty()) {
        cout << "Error: The stack is empty. no word to pop.\n";
        return;       // Low-level validation for empty stack
    }
    else {
        StackNode* temp = nullptr;    // Temperoray pointer
        // Pop value off at the top of the stack
        word = top->value;
        temp = top->next;
        delete top;
        top = temp;
        return;
    }
}


// Member Function Definition
// ********************************************************
// name:      isEmpty
// called by: pop, capitalize
// passed:    nothing
// returns:   bool status
// calls:     nothing
// The isEmpty function check the status of the stack     *
// ********************************************************
bool WordStack::isEmpty() {
    bool status;
    if (!top) {        // If top is nullptr, then the list is empty
        status = true;
    }
    else {             // Otherwise, the list contains at least one node
        status = false;
    }
    return status;
}

// Member Function Definition
// ********************************************************
// name:      getLength const
// called by: displayStack, capitalizeStack
// passed:    nothing
// returns:   nothing
// calls:     nothing
// The getLength function count the number of elements    *
// on the stack                                           *
// ********************************************************
int WordStack::getLength() const {
    int length = 0;
    StackNode* nodePtr = top;   // Position nodePtr at the top of the stack
    if (!nodePtr) {
        return 0;
    };
    
    // Traverse the list counting each node
    while (nodePtr) {          // Continue move to next until nodePtr is nullptr
        length++;
        nodePtr = nodePtr->next;
    }
    return length;
}


// Member Function Definition
// ********************************************************
// name:      traverse const
// called by: displayStack
// passed:    nothing
// returns:   vector<string> wordList
// calls:     nothing
// The traverse function get the value of element on      *
// the stack                                              *
// ********************************************************
vector<string> WordStack::traverse() const {
    vector<string> wordList;
    StackNode* nodePtr = nullptr;
    StackNode* nextPtr = nullptr;
    nodePtr = top;    // Position nodePtr at the top of the stack
    
    // Traverse each node from the top of the stack array,
    // and appending each node value to the vector 
    while (nodePtr != nullptr) {
        nextPtr = nodePtr->next;
        wordList.push_back(nodePtr->value);
        nodePtr = nextPtr;
    }
    return wordList;
}


// Member Function Definition
// ********************************************************
// name:      capitalize
// called by: capitalizeStack
// passed:    nothing
// returns:   nothing
// calls:     isEmpty
// The capitalize function capitalize all the words       *
// on the stack                                           *
// ********************************************************
void WordStack::capitalize() {
    if (isEmpty()) {
        cout << "Error: The stack is empty, no word to capitalize.\n";
        return;           // Low-level validation for empty stack
    }
    else {
        StackNode* nodePtr = top;         // Position nodePtr at the top of the stack
        StackNode* nextPtr = nullptr;
        string word;
        
        // Traverse each node from the top of the stack array,
        // and appending each node value to the vector
        while (nodePtr != nullptr) {
            nextPtr = nodePtr->next;
            word = nodePtr->value;
            for (char &c : word) {        // Covert all characters to upper case
                c = toupper(c);
            }
            nodePtr->value = word;        // Save capitalized word back to stack
            nodePtr = nextPtr;
        }
        return;
    }
}

