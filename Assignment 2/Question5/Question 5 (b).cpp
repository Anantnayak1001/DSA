#include <iostream>
using namespace std;

void PrintArray(int* array, int length) {
	for(int i = 0; i < length; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
}

int main()
{
    int tridiagonal_matrix[4][4] = {{15, 3, 0, 0},
                                   {90, 25, 5, 0},
                                   {0, 80, 35, 7},
                                   {0, 0, 70, 45}};
    
    int matrix_dimension = sizeof(tridiagonal_matrix[0]) / sizeof(tridiagonal_matrix[0][0]);
    
    int principal_diagonal[matrix_dimension];
    int upper_diagonal[matrix_dimension - 1];
    int lower_diagonal[matrix_dimension - 1];
    
    for(int row = 0; row < matrix_dimension; row++){
        principal_diagonal[row] = tridiagonal_matrix[row][row];
        
        if(row < matrix_dimension - 1){
            upper_diagonal[row] = tridiagonal_matrix[row][row + 1];
        }
        
        if(row > 0){
            lower_diagonal[row - 1] = tridiagonal_matrix[row][row - 1];
        }
    }
    
    cout << "Principal diagonal elements: ";
    PrintArray(principal_diagonal, matrix_dimension);
    
    cout << "Upper diagonal elements: ";
    PrintArray(upper_diagonal, matrix_dimension - 1);
    
    cout << "Lower diagonal elements: ";
    PrintArray(lower_diagonal, matrix_dimension - 1);
    
    return 0;
}