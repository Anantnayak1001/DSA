#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindDifferencePairs(vector<int>&numbers, int target_diff){
    int size = numbers.size();
    sort(numbers.begin(), numbers.end());
    int pair_count = 0;

    int left_ptr = 0, right_ptr = 0;

    while(right_ptr < size){
        if(left_ptr == right_ptr){
            right_ptr++;
            continue;
        }
        
        int current_diff = numbers[right_ptr] - numbers[left_ptr];
        
        if(current_diff < target_diff){
            right_ptr++;
        }
        else if(current_diff > target_diff){
            left_ptr++;
        }
        else{
            int left_value = numbers[left_ptr];
            int right_value = numbers[right_ptr];
            int left_count = 0, right_count = 0;

            while(left_ptr < size && numbers[left_ptr] == left_value){
                left_ptr++;
                left_count++;
            }

            while(right_ptr < size && numbers[right_ptr] == right_value){
                right_ptr++;
                right_count++;
            }
           
           if(left_value == right_value){
                pair_count += (left_count * (left_count - 1)) / 2;
           }
           else{
                pair_count += left_count * right_count;
           }
        }
    }
    return pair_count;
}

int main(){
    vector<int> data = {1, 4, 6, 2, 8, 4, 4, 10};
    int difference_target = 2;
    int result = FindDifferencePairs(data, difference_target);
    cout << "Number of pairs with difference " << difference_target << ": " << result;
    
    return 0;
}