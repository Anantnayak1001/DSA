#include<iostream>
#include<vector>
using namespace std;

void DuplicateTwos(vector<int> &numbers){
    int last_index = numbers.size() - 1;
    int duplicate_count = 0;

    // First pass: count potential duplicates and find valid range
    for(int current = 0; current <= last_index - duplicate_count; current++){
        if (numbers[current] == 2){
            if (current == last_index - duplicate_count){
                numbers[last_index] = 2;
                last_index--;
                break;
            }
            duplicate_count++;
        }
    }

    int write_position = last_index - duplicate_count;

    // Second pass: process from right to left
    for(int i = write_position; i >= 0; i--){
        if(numbers[i] == 2){
            numbers[i + duplicate_count] = 2;
            duplicate_count--;
            numbers[i + duplicate_count] = 2;
        }
        else{
            numbers[i + duplicate_count] = numbers[i];
        }
    }
    // Time Complexity: O(2N) = O(N)
}

int main(){
    vector<int> data = {4, 3, 0, 2, 9, 5, 2, 2, 7, 2, 8, 2};
    DuplicateTwos(data);
    
    cout << "Modified array: ";
    for(int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
    cout << endl;
    
    return 0;
}