#include<iostream>
#include<stack>
using namespace std;

int GetOperatorPrecedence(char operatorChar) {
    if (operatorChar == '^')
        return 3;
    else if (operatorChar == '/' || operatorChar == '*')
        return 2;
    else if (operatorChar == '+' || operatorChar == '-')
        return 1;
    else
        return -1;
}

string ConvertInfixToPostfix(string &infixExpression) {
    int expressionLength = infixExpression.length();
    int currentIndex = 0;
    stack<char> operatorStack;
    string postfixResult = "";

    while (currentIndex < expressionLength) {
        char currentCharacter = infixExpression[currentIndex];
        
        if ((currentCharacter >= 'A' && currentCharacter <= 'Z') ||
            (currentCharacter >= 'a' && currentCharacter <= 'z') ||
            (currentCharacter >= '0' && currentCharacter <= '9')) {
            postfixResult += currentCharacter;
        }
        else if (currentCharacter == '(') {
            operatorStack.push(currentCharacter);
        }
        else if (currentCharacter == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixResult += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        }
        else {
            while (!operatorStack.empty() && 
                   GetOperatorPrecedence(currentCharacter) <= GetOperatorPrecedence(operatorStack.top())) {
                postfixResult += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(currentCharacter);
        }
        currentIndex++;
    }
    
    while (!operatorStack.empty()) {
        postfixResult += operatorStack.top();
        operatorStack.pop();
    }
    
    return postfixResult;
}

int main() {
    string inputExpression = "a+b*c";
    cout << "Infix Expression: " << inputExpression << endl;
    
    string postfixOutput = ConvertInfixToPostfix(inputExpression);
    cout << "Postfix Expression: " << postfixOutput << endl;

    // Additional test cases
    string test2 = "(a+b)*c";
    string test3 = "a+b*(c^d-e)^(f+g*h)-i";
    
    cout << "\nAdditional conversions:" << endl;
    cout << "Infix: " << test2 << " -> Postfix: " << ConvertInfixToPostfix(test2) << endl;
    cout << "Infix: " << test3 << " -> Postfix: " << ConvertInfixToPostfix(test3) << endl;

    return 0;
}