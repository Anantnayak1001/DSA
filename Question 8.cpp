#include <iostream>
#include <unordered_map>
using namespace std;

int CountUniqueElements(int *dataset, int size){
    if(size == 0) return 0;
    
    int unique_count = 1;
    for(int current = 1; current < size; current++){
        bool duplicate_found = false;
        for(int previous = 0; previous < current; previous++){
            if(dataset[current] == dataset[previous]){
                duplicate_found = true;
                break;
            }
        }
        if(!duplicate_found){
            unique_count++;
        }
    }
    return unique_count;
    //Time Complexity: O(N²)
    //Space Complexity: O(1)
}

void ExchangeValues(int &first, int &second)
{
    int temporary = first;
    first = second;
    second = temporary;
}

void SortArray(int *array, int elements)
{
    for (int outer = 0; outer < elements; outer++)
    {
        for(int inner = 0; inner < elements - outer - 1; inner++)
        {
            if (array[inner] > array[inner + 1])
            {
                ExchangeValues(array[inner], array[inner + 1]);
            }
        }
    }
}

int CountUniqueSorted(int *array, int elements){
    if(elements == 0) return 0;
    
    SortArray(array, elements);
    
    int unique_count = 1;
    for(int index = 1; index < elements; index++){
        if(array[index] != array[index - 1]){
            unique_count++;
        }
    }
    return unique_count;
    //Time Complexity: O(N²) - can be optimized with better sorting
    //Space Complexity: O(1)
}

int CountUniqueOptimal(int *array, int elements){
    unordered_map<int, bool> element_map;
    
    for(int i = 0; i < elements; i++){
        element_map[array[i]] = true;
    }
    
    return element_map.size();
    //Time Complexity: O(N)
    //Space Complexity: O(N)
}

int main()
{
    int numbers[5] = {2, 6, 2, 3, 3};
    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    
    int distinct_count = CountUniqueOptimal(numbers, array_size);
    cout << "Number of distinct elements: " << distinct_count;

    return 0;
}