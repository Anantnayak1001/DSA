#include <iostream>
using namespace std;

int FindMissingLinear(int *sequence, int length){
    int total_sum = ((length + 1) * (length + 2)) / 2;
    
    int actual_sum = 0;
    for(int counter = 0; counter < length; counter++){
        actual_sum += sequence[counter];
    }
    
    return total_sum - actual_sum;
}

int FindMissingBinary(int *data, int elements){
    int left = 0;
    int right = elements - 1;
    
    while(left <= right){
        int center = left + (right - left) / 2;
        
        if((data[center] != (center + 1)) && (data[center - 1] == center)){
            return center + 1;
        }
        
        else if(data[center] == (center + 1)){
            left = center + 1;
        }
        
        else{
            right = center - 1;
        }
    }
    return -1;
}

int main()
{
    int numbers[5] = {1, 2, 3, 5, 6};
    
    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    
    int missing_value = FindMissingBinary(numbers, array_size);
    cout << "The number that is missing: " << missing_value;

    return 0;
}