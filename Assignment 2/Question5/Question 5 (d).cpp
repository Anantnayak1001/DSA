#include <iostream>
using namespace std;

void PrintCompressedData(int* storage_array, int element_count) {
	for(int index = 0; index < element_count; index++) {
		cout << storage_array[index] << "\t";
	}
	cout << endl;
}

int main()
{
    int upper_triangular[4][4] = {{3, 6, 9, 12},
                                 {0, 5, 8, 11},
                                 {0, 0, 7, 10},
                                 {0, 0, 0, 4}};
    
    int dimension = sizeof(upper_triangular[0]) / sizeof(upper_triangular[0][0]);
    
    int total_storage_elements = (dimension * (dimension + 1)) / 2;
    
    int compressed_upper[total_storage_elements];
    int current_index = 0;
    
    for(int row = 0; row < dimension; row++) {
        for(int column = row; column < dimension; column++) {
            compressed_upper[current_index] = upper_triangular[row][column];
            current_index++;
        }
    }
    
    cout << "Compressed upper triangular elements (row-major order):" << endl;
    PrintCompressedData(compressed_upper, total_storage_elements);
    
    // Demonstration: Accessing element at position [1][2] using formula
    int test_row = 1, test_col = 2;
    if(test_row <= test_col) {
        int position = test_row * dimension - (test_row * (test_row - 1)) / 2 + (test_col - test_row);
        cout << "Element at [" << test_row << "][" << test_col << "]: " 
             << compressed_upper[position] << endl;
    }

    return 0;
}
// Elements are stored in Row Major Order.
// Access formula: position = row*n - (row*(row-1))/2 + (column - row)