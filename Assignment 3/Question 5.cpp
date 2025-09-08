#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int CalculatePostfixExpression(string &expression) {
    stack<int> operandStack;

    for (int index = 0; index < expression.length(); index++) {
        char currentChar = expression[index];

        if (isdigit(currentChar)) {
            operandStack.push(currentChar - '0');  // Convert character to integer
        }
        else {
            // Operator encountered - pop two operands
            int secondOperand = operandStack.top(); 
            operandStack.pop();
            int firstOperand = operandStack.top(); 
            operandStack.pop();

            switch (currentChar) {
                case '+': 
                    operandStack.push(firstOperand + secondOperand); 
                    break;
                case '-': 
                    operandStack.push(firstOperand - secondOperand); 
                    break;
                case '*': 
                    operandStack.push(firstOperand * secondOperand); 
                    break;
                case '/': 
                    operandStack.push(firstOperand / secondOperand); 
                    break;
                case '^': 
                    operandStack.push(pow(firstOperand, secondOperand)); 
                    break;
                default:
                    cout << "Invalid operator encountered!" << endl;
                    return -1;
            }
        }
    }
    return operandStack.top();
}

int main() {
    string postfixExpr1 = "23+5*";
    string postfixExpr2 = "52-3*";
    string postfixExpr3 = "23*4+";
    
    cout << "Postfix Expression Evaluation:" << endl;
    cout << "Expression: " << postfixExpr1 << " = " << CalculatePostfixExpression(postfixExpr1) << endl;
    cout << "Expression: " << postfixExpr2 << " = " << CalculatePostfixExpression(postfixExpr2) << endl;
    cout << "Expression: " << postfixExpr3 << " = " << CalculatePostfixExpression(postfixExpr3) << endl;

    return 0;
}