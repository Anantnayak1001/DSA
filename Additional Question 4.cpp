#include<iostream>
#include<vector>
using namespace std;

void SortThreeValues(vector<int> &numbers){
    int size = numbers.size();
    int left = 0, current = 0, right = size - 1;

    while(current <= right){
        if(numbers[current] == 0){
            swap(numbers[left], numbers[current]);
            left++;
            current++;
        }
        else if(numbers[current] == 1){
            current++;
        }
        else{
            swap(numbers[current], numbers[right]);
            right--;
        }
    }
    // Time Complexity: O(N)
    // Space Complexity: O(1)
}

int main(){
    vector<int> values = {1, 0, 0, 2, 1, 2, 2, 2, 1, 0};
    SortThreeValues(values);
    
    cout << "Sorted array: ";
    for(int i = 0; i < values.size(); i++){
        cout << values[i] << " ";
    }
    cout << endl;
    
    return 0;
}