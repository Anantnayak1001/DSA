#include<iostream>
#include<stack>
using namespace std;

bool CheckParenthesesBalance(string &expression) {
    stack<char> bracketStack;
    
    for (int position = 0; position < expression.length(); position++) {
        char currentChar = expression[position];
        
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            bracketStack.push(currentChar);
        }
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            if(bracketStack.empty()) return false;
            
            char topElement = bracketStack.top();
            
            if (currentChar == ')' && topElement == '(') {
                bracketStack.pop();
            }
            else if (currentChar == ']' && topElement == '[') {
                bracketStack.pop();
            }
            else if (currentChar == '}' && topElement == '{') {
                bracketStack.pop();
            }
            else {
                return false;
            }
        }
    }
    
    return bracketStack.empty();
}

int main() {
    string testExpression = "()[{}()]";
    
    cout << "Expression: " << testExpression << endl;
    cout << "Are parentheses balanced? ";
    
    if (CheckParenthesesBalance(testExpression)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    // Additional test cases
    string test2 = "({[}])";
    string test3 = "({[]})";
    
    cout << "\nAdditional tests:" << endl;
    cout << "Expression: " << test2 << " -> " << (CheckParenthesesBalance(test2) ? "Yes" : "No") << endl;
    cout << "Expression: " << test3 << " -> " << (CheckParenthesesBalance(test3) ? "Yes" : "No") << endl;

    return 0;
}