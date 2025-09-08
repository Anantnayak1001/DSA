#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> FindNextGreaterElements(vector<int> &inputArray) {
    int arraySize = inputArray.size();
    stack<int> elementStack;
    vector<int> result(arraySize);

    for (int currentIndex = arraySize - 1; currentIndex >= 0; currentIndex--) {
        while (!elementStack.empty() && elementStack.top() <= inputArray[currentIndex]) {
            elementStack.pop();
        }

        result[currentIndex] = elementStack.empty() ? -1 : elementStack.top();
        elementStack.push(inputArray[currentIndex]);
    }

    return result;
}

void PrintArray(const vector<int> &outputArray) {
    for(int i = 0; i < outputArray.size(); i++) {
        cout << outputArray[i] << "\t";
    }
    cout << endl;
}

int main() {
    vector<int> testData = {2, 4, 3, 1, 8, 5, 9, 88};
    
    vector<int> nextGreaterResults = FindNextGreaterElements(testData);

    cout << "Next Greater Elements: ";
    PrintArray(nextGreaterResults);
    
    return 0;
}