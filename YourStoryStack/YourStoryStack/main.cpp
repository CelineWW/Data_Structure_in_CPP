/*
 *
 * Celine Wang
 *
 * Chapter 9, Programming Your Story Stack with WordStack class
 *
 * Apr 2024
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "WordStack.h"
using namespace std;

// Function declarations
void displayInstruction();
void displayMenu();
void pushStack(WordStack &);
void popStack(WordStack &, string &);
void displayStack(const WordStack &);
void capitalizeStack(WordStack &);
void makeStory(WordStack &, string, string &);
int countStar(const string &);
void exitProgram();

int main() {
    displayInstruction();
    
    // Create a WordStack object.
    WordStack stack;
    // To hold values popped off the stack
    string catchWord;
    
    // * represents the word that need to be replaced
    string story = "It's a * day today.\nMy * boy was chasing his * dog in a * park.\nHe saw his * friend.\nThey were playing * game the whole day.\n";
    
    
    int choice = 0;
    // Continually display the menu until user choose to quit
    while(choice != 6) {
        displayMenu();
        cout << "Please choose a menu option: ";
        cin >> choice;
        // Continually prompt user input until valid
        if (cin.fail()) {
            cout << "Choose a number from the menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Choose from main menu
        switch (choice) {
            case 1:
                pushStack(stack);
                break;
            case 2:
                popStack(stack, catchWord);
                break;
            case 3:
                capitalizeStack(stack);
                break;
            case 4:
                displayStack(stack);
                break;
            case 5:
                makeStory(stack, story, catchWord);
                break;
            case 6:
                exitProgram();
                break;
            default:
                cout << "Invalid enter! Choose an option between 1-6.\n";
        }
    }
    return 0;
}

// ********************************************************
// name:      displayInstruction
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayMenu function display the instruction of    *
// story game (explain the menu)                          *
// ********************************************************
void displayInstruction() {
    cout << "\n****** Make Your Own Story ******\n\n";
    cout << "Create your own dynamic stack of words to fill in a story.\n";
    cout << "You must have enough words on the stack, otherwise story will not show.\n";
    cout << "You have the following options:\n";
    cout << "1. Push (an adjective word onto the stack)\n";
    cout << "2. Pop (a word off the stack)\n";
    cout << "3. Capitalize all of the words on the stack\n";
    cout << "4. Display Stack\n";
    cout << "5. Make a Story (Pop words from the stack and use them\n";
    cout << "   to fill in the blanks of a story that you have created.\n";
    cout << "   Display the story.\n";
    cout << "6. Exit - exit the program\n\n";
    cout << " ------ Game Start ------> \n\n";
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The displayMenu function display the menu of story     *
// processing options                                     *
// ********************************************************
void displayMenu() {
    cout << "\nStory Game Menu\n";
    cout << "1. Push a word\n";
    cout << "2. Pop a word\n";
    cout << "3. Capitalize my stack\n";
    cout << "4. Display Stack\n";
    cout << "5. Make a Story\n";
    cout << "6. Exit\n\n";
}

// ********************************************************
// name:      pushStack
// called by: main
// passed:    WordStack &stack
// returns:   nothing
// calls:     WordStack::push(string)
// The pushStack function get user input of a word and    *
// push the words with help of WorkStack push member      *
// function                                               *
// ********************************************************
void pushStack(WordStack &stack) {
    string myWord = "";
    bool validWord = false;
    bool emptyFlag = false;
    bool firstPrompt = true;

    // Loop through prompt to get valid word to push
    while (!validWord) {
        // To avoid print "Push" for twice with initial empty word
        if (!firstPrompt) {
            cout << "Push ";
        }
        firstPrompt = false;
        getline(cin, myWord);      // Getline to handle empty word
        
        // Empty string is not accepted
        if (myWord.empty()) {
            if (emptyFlag) {
                cout << "Sorry! Empty input is not allowed.\n";
            }
            emptyFlag = true;
            continue;
        }
        emptyFlag = false;
        
        // Word length must between 1 and 10
        if (myWord.size() < 1 || myWord.size() > 10) {
            validWord = false;
            cout << "Sorry! Word legnth must be between 1 and 10.\n";
            continue;
        }
        else {  // All character in word must be letters
            for (char c : myWord) {
                if (!isalpha(c)) {
                    validWord = false;
                    cout << "Sorry! The character in word must be all letters.\n";
                    break;
                }
                else {
                    validWord = true;
                }
            }
        }
    }
    stack.push(myWord);
}

// ********************************************************
// name:      popStack
// called by: main
// passed:    WordStack &stack
// returns:   nothing
// calls:     WordStack::pop(string &)
//            WordStack::isEmpty()
// The popStack function pop the word on the top of the   *
// stack and save it to variable with help of WorkStack   *
// pop member function                                    *
// ********************************************************
void popStack(WordStack &stack, string &popped) {
    if (stack.isEmpty()) {
        cout << "Sorry! The stack is empty, no word to pop.\n";
        return;
    }
    else {
        stack.pop(popped);
        return;
    }
}


// ********************************************************
// name:      displayStack(WordStack &)
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     vector<string> WordStack::traverse() const
//            int WordStack::getLength() const
// The displayStack function display the words with help  *
// of WorkStack traverse member function                  *
// ********************************************************
void displayStack(const WordStack &stack) {
    // Get vector of words on the stack
    vector<string> words = stack.traverse();
    // loop each element and display in reverse order
    if (words.size() == 0) {
        cout << "The stack is empty.\n";
    }
    else {
        for (int i = 0; i < (int)words.size(); i++) {
            cout << words[i] << endl;
        }
        cout << "There are " << stack.getLength() << " words on the stack.\n";
    }
}


// ********************************************************
// name:      capitalizeStack
// called by: main
// passed:    WordStack &stack
// returns:   nothing
// calls:     void WordStack::capitalize()
//            int WordStack::getLength()
// The capitalizeStack function capitalize the words with *
// help of WorkStack traverse member function             *
// ********************************************************
void capitalizeStack(WordStack &stack) {
    if (stack.getLength() == 0) {
        cout << "Sorry! The stack is empty, no word to capitalize.\n";
        return;
    }
    else {
        cout << "All words on the stack are Capitalized successfully!\n";
        stack.capitalize();
        return;
    }
}


// ********************************************************
// name:      makeStory
// called by: main
// passed:    WordStack &stack
// returns:   nothing
// calls:     void popStack(WordStack &stack, string &popped)
//            int WordStack::getLength()
//            int countStar(const string &paragraph)
// The makeStory function get the number of star in the   *
// story and replace all the stars with popped words from *
// the stack                                              *
// ********************************************************
void makeStory(WordStack &stack, string paragraph, string &popped) {
    // Get star count to compare if words are enough
    int starCount = countStar(paragraph);
    int wordCount = stack.getLength();

    if (wordCount < starCount) {
        cout << "Words are not enough to make a story.\n";
        return;
    }
    else {   // If words are enough, replace stars with words and display story.
        size_t position = paragraph.find("*");
        while (position != string::npos) {
            popStack(stack, popped);
            paragraph.replace(position, 1, popped);
            position = paragraph.find("*", position + popped.length());
        }
    }
    cout << "Make a Story:\n";
    cout << paragraph << endl;
}


// ********************************************************
// name:      countStar
// called by: main
// passed:    const string &paragraph
// returns:   int starCount
// calls:     nothing
// The countStar function count the stars in the story    *
// These stars need to be replaced by words later         *
// ********************************************************
int countStar(const string &paragraph) {
    int starCount = 0;
    for (char c : paragraph) {
        if (c == '*') {
            starCount++;
        }
    }
    return starCount;
}


// ********************************************************
// name:      exitProgram()
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     nobody
// The exitProgram function terminate the program         *
// ********************************************************
void exitProgram() {
    cout << "Bye! I hope you had fun with this story game!\n";
    cout << "-----------------------------------------------------\n";
}
