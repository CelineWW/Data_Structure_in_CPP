/*
 *
 * Celine Wang
 *
 * Specification(Header) file for WordStack class
 * of Chapter 19, Programming Your Story Stack
 *
 * Apr 2024
 *
 */


#ifndef WordStack_h
#define WordStack_h
#include <string>
#include <vector>
using namespace std;

class WordStack {
private:
    // Structure for the stack nodes
    struct StackNode {
        string value;                 // Value in the node
        StackNode* next;             // Pointer to the next node
    };
    StackNode* top;                  // Pointer to the stack top
    
public:
    // Constructor
    WordStack () {top = nullptr;}
    
    // Destructor
    ~WordStack();
    
    // Stack operartions
    void push(string);
    void pop(string &);
    bool isEmpty();
    int getLength() const;
    vector<string> traverse() const;
    void capitalize();
};
#endif /* WordStack_h */
