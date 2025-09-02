#include <iostream>
using namespace std;

void PrintCompressedArray(int* compressed_data, int element_count) {
	for(int index = 0; index < element_count; index++) {
		cout << compressed_data[index] << "\t";
	}
	cout << endl;
}

int main()
{
    int lower_triangular[4][4] = {{5, 0, 0, 0},
                                 {2, 8, 0, 0},
                                 {1, 4, 7, 0},
                                 {3, 6, 9, 12}};
    
    int matrix_size = sizeof(lower_triangular[0]) / sizeof(lower_triangular[0][0]);
    
    int total_elements = (matrix_size * (matrix_size + 1)) / 2;
    
    int compressed_storage[total_elements];
    int storage_index = 0;
    
    for(int row = 0; row < matrix_size; row++) {
        for(int column = 0; column <= row; column++) {
            compressed_storage[storage_index] = lower_triangular[row][column];
            storage_index++;
        }
    }
    
    cout << "Compressed lower triangular elements (row-major order):" << endl;
    PrintCompressedArray(compressed_storage, total_elements);
    
    // Demonstration: Accessing element at position [2][1] using formula
    int test_row = 2, test_col = 1;
    if(test_row >= test_col) {
        int position = (test_row * (test_row + 1)) / 2 + test_col;
        cout << "Element at [" << test_row << "][" << test_col << "]: " 
             << compressed_storage[position] << endl;
    }

    return 0;
}
// Elements are stored in Row Major Order.
// Access formula: position = row*(row+1)/2 + column