#include <iostream>
#include <vector>
using namespace std;

int CountInversionsBruteForce(int *data, int size){
    int inversion_count = 0;
    
    for(int first_index = 0; first_index < size; first_index++){
        for(int second_index = first_index + 1; second_index < size; second_index++){
            if(data[second_index] < data[first_index]){
                inversion_count++;
            }
        }
    }
    return inversion_count;
    // Time Complexity: O(N²)
    // Space Complexity: O(1)
}

int MergeAndCount(int *array, int start, int middle, int end){
    vector<int> temporary;
    int left_ptr = start;
    int right_ptr = middle + 1;
    int inversion_count = 0;
    
    while(left_ptr <= middle && right_ptr <= end){
        if(array[left_ptr] <= array[right_ptr]){
            temporary.push_back(array[left_ptr]);
            left_ptr++;
        }
        else{
            temporary.push_back(array[right_ptr]);
            inversion_count += (middle - left_ptr + 1);
            right_ptr++;
        }
    }
    
    while(left_ptr <= middle){
        temporary.push_back(array[left_ptr]);
        left_ptr++;
    }
    
    while(right_ptr <= end){
        temporary.push_back(array[right_ptr]);
        right_ptr++;
    }
    
    for(int position = start; position <= end; position++){
        array[position] = temporary[position - start];
    }
    
    return inversion_count;
}

int CountInversionsEfficient(int *array, int start, int end){
    int total_inversions = 0;
    
    if(start >= end){
        return total_inversions;
    }
    
    int midpoint = start + (end - start) / 2;
    total_inversions += CountInversionsEfficient(array, start, midpoint);
    total_inversions += CountInversionsEfficient(array, midpoint + 1, end);
    total_inversions += MergeAndCount(array, start, midpoint, end);
    
    return total_inversions;
    // Time Complexity: O(N·log(N))
    // Space Complexity: O(N)
}

int main()
{
   int numbers[7] = {1, 3, 2, 5, 7, 6, 4};
   int array_size = sizeof(numbers) / sizeof(numbers[0]);
   
   int inversion_count = CountInversionsEfficient(numbers, 0, array_size - 1);
   cout << "Total number of inversions: " << inversion_count;

   return 0;
}