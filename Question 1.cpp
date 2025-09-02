#include <iostream>
using namespace std;

int Fast_Search(int *data, int size, int key){
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        int middle = start + (end - start) / 2;  // Alternative calculation to prevent overflow
        
        if(data[middle] == key){
            return middle;
        }
        
        else if(data[middle] > key){
            end = middle - 1;
        }
        
        else{
            start = middle + 1;
        }
    }
    
    return -1;
}

int main()
{
    int numbers[6] = {10, 20, 30, 40, 50, 60};
    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    
    int search_value = 50;
    int position = Fast_Search(numbers, array_size, search_value);
    
    cout << "The position of the element is: ";
    cout << position;
    
    return 0;
}