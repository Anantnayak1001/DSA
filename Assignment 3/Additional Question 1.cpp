#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> FindPreviousSmallerElements(vector<int> &inputArray) {
    int size = inputArray.size();
    stack<int> elementStack;
    vector<int> result(size);

    for (int currentIndex = 0; currentIndex < size; currentIndex++) {
        while (!elementStack.empty() && elementStack.top() >= inputArray[currentIndex]) {
            elementStack.pop();
        }

        result[currentIndex] = elementStack.empty() ? -1 : elementStack.top();
        elementStack.push(inputArray[currentIndex]);
    }

    return result;
}

void PrintVector(vector<int> &output) {
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << "\t";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {2, 4, 3, 1, 8, 5, 9, 88};
    
    vector<int> previousSmaller = FindPreviousSmallerElements(numbers);

    cout << "Original array: ";
    PrintVector(numbers);
    
    cout << "Nearest smaller elements: ";
    PrintVector(previousSmaller);
    
    return 0;
}