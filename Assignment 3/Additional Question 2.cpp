#include<iostream>
#include<stack>
using namespace std;

class SpecialStack {
    stack<int> dataStack;
    int currentMinimum;

public:
    SpecialStack() { 
        currentMinimum = INT_MAX; 
    }

    void addElement(int val) {
        if (dataStack.empty()) {
            dataStack.push(val);
            currentMinimum = val;
        }
        else if (val > currentMinimum) {
            dataStack.push(val);
        }
        else {
            dataStack.push(2 * val - currentMinimum);
            currentMinimum = val;
        }
    }

    void removeElement() {
        if(dataStack.size() == 1){
            currentMinimum = INT_MAX;
            dataStack.pop();
        }
        else {
            int topElement = dataStack.top();
            dataStack.pop();
            if (topElement < currentMinimum) {
                currentMinimum = 2 * currentMinimum - topElement;
            }
        }
    }

    int peekTop() {
        if (dataStack.top() > currentMinimum) {
            return dataStack.top();
        }
        return currentMinimum;
    }

    int findMinimum() { 
        return currentMinimum; 
    }
};

int main(){
    SpecialStack customStack;
    
    customStack.addElement(4);
    customStack.addElement(7);
    customStack.addElement(3);
    customStack.addElement(2);
    
    customStack.removeElement();
    cout << "Current minimum: " << customStack.findMinimum() << endl;
    
    customStack.removeElement();
    cout << "Current minimum: " << customStack.findMinimum() << endl;
    
    customStack.removeElement();
    cout << "Current minimum: " << customStack.findMinimum() << endl;
    
    customStack.removeElement();
    cout << "Current minimum: " << customStack.findMinimum() << endl;
    
    return 0;
}