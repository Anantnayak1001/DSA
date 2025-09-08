#include <iostream>
using namespace std;

void Exchange(int &first, int &second){
    int temporary = first;
    first = second;
    second = temporary;
}

void Sorting_Algorithm(int *dataset, int elements){
    
    for(int round = 0; round < elements - 1; round++){
        bool swapped = false;
        for(int position = 0; position < elements - round - 1; position++){
            if(dataset[position] > dataset[position + 1]){
                Exchange(dataset[position], dataset[position + 1]);
                swapped = true;
            }
        }
        // Early termination if no swaps occurred
        if (!swapped) break;
    }
}

int main()
{
   int numbers[7] = {64, 34, 25, 12, 22, 11, 90};
   int count = sizeof(numbers) / sizeof(numbers[0]);
   
   Sorting_Algorithm(numbers, count);
   
   cout << "Array after sorting: " << endl;
   for(int index = 0; index < count; index++){
       cout << numbers[index] << "\t";
   }
   cout << endl;
   
   return 0;
}