#include<iostream>
using namespace std;

class ArrayStack {
    int *storage;
    int capacity;
    int topIndex;

public:
    ArrayStack() {
        capacity = 10;
        storage = new int[capacity];
        topIndex = -1;
    }

    bool checkFull() {
        if(topIndex == capacity - 1) {
            cout << endl << "Stack has reached maximum capacity" << endl;
            return true;
        }
        return false;
    }

    void addElement(int value) {
        if(checkFull()) return;

        topIndex++;
        storage[topIndex] = value;
        cout << value << " added to stack" << endl;
    }

    bool checkEmpty() {
        if(topIndex == -1) {
            cout << endl << "Stack is currently empty" << endl;
            return true;
        }
        return false;
    }

    void removeElement() {
        if(checkEmpty()) return;

        cout << storage[topIndex] << " removed from stack" << endl;
        topIndex--;
    }

    int viewTop() {
        if(checkEmpty()) return -1;

        return storage[topIndex];
    }

    void showStack() {
        if(checkEmpty()) return;
        
        cout << "Stack elements (top to bottom): ";
        for(int i = topIndex; i >= 0; i--) {
            cout << storage[i] << " ";
        }
        cout << endl;
    }

    ~ArrayStack() {
        delete[] storage;
    }
};

int main() {
    ArrayStack myStack;
    int choice, value;

    do {
        cout << "\n=== Stack Operations Menu ===" << endl;
        cout << "1. Add Element (Push)" << endl;
        cout << "2. Remove Element (Pop)" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. View Top Element" << endl;
        cout << "6. Display Stack" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                myStack.addElement(value);
                break;
            case 2:
                myStack.removeElement();
                break;
            case 3:
                myStack.checkEmpty();
                break;
            case 4:
                myStack.checkFull();
                break;
            case 5:
                value = myStack.viewTop();
                if(value != -1) {
                    cout << "Top element: " << value << endl;
                }
                break;
            case 6:
                myStack.showStack();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 7);

    return 0;
}
