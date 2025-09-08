#include<iostream>
#include<stack>
using namespace std;

void InvertTextUsingStack(string &inputText) {
    stack<char> characterStack;
    int textLength = inputText.length();
    
    // Push all characters onto the stack
    for(int currentIndex = 0; currentIndex < textLength; currentIndex++) {
        characterStack.push(inputText[currentIndex]);
    }

    // Pop characters from stack to reverse the string
    for(int currentIndex = 0; currentIndex < textLength; currentIndex++) {
        inputText[currentIndex] = characterStack.top();
        characterStack.pop();
    }
}

int main() {
    string originalString = "DataStructure";
    cout << "Original string: " << originalString << endl;
    
    InvertTextUsingStack(originalString);
    
    cout << "Reversed string: " << originalString << endl;

    return 0;
}