#include <iostream>
using namespace std;

void PrintCompressedMatrix(int* matrix_data, int element_count) {
	for(int position = 0; position < element_count; position++) {
		cout << matrix_data[position] << "\t";
	}
	cout << endl;
}

int main()
{
    int symmetric_matrix[4][4] = {{2, 4, 6, 8},
                                 {4, 5, 7, 9},
                                 {6, 7, 3, 1},
                                 {8, 9, 1, 4}};
    
    int matrix_order = sizeof(symmetric_matrix[0]) / sizeof(symmetric_matrix[0][0]);
    
    int compressed_size = (matrix_order * (matrix_order + 1)) / 2;
    
    int compressed_storage[compressed_size];
    int storage_index = 0;
    
    // Store upper triangular part (including diagonal)
    for(int row = 0; row < matrix_order; row++) {
        for(int column = row; column < matrix_order; column++) {
            compressed_storage[storage_index] = symmetric_matrix[row][column];
            storage_index++;
        }
    }
    
    cout << "Compressed symmetric matrix elements (upper triangular storage):" << endl;
    PrintCompressedMatrix(compressed_storage, compressed_size);
    
    // Demonstration: Accessing element at position [2][1] using symmetry property
    int test_row = 2, test_col = 1;
    if(test_row >= test_col) {
        // For lower triangular elements, use symmetry: a[i][j] = a[j][i]
        int position = test_col * matrix_order - (test_col * (test_col - 1)) / 2 + (test_row - test_col);
        cout << "Element at [" << test_row << "][" << test_col << "]: " 
             << compressed_storage[position] << endl;
    } else {
        int position = test_row * matrix_order - (test_row * (test_row - 1)) / 2 + (test_col - test_row);
        cout << "Element at [" << test_row << "][" << test_col << "]: " 
             << compressed_storage[position] << endl;
    }

    return 0;
}
// Elements are stored using upper triangular portion
// Access formula for upper triangular: position = row*n - (row*(row-1))/2 + (column - row)
// For symmetric access: if row >= column, use a[column][row] position