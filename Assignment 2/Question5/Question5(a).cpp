#include <iostream>
using namespace std;

int main()
{
	int original_matrix[3][3] = {{15, 0, 0},
                                {0, 25, 0},
                                {0, 0, 35}};
    
    int dimension = sizeof(original_matrix[0]) / sizeof(original_matrix[0][0]);
    
    int diagonal_elements[dimension];
    
    for(int row = 0; row < dimension; row++) {
        diagonal_elements[row] = original_matrix[row][row];
    }
    
    // Demonstration: Accessing diagonal elements
    cout << "Compressed diagonal elements: ";
    for(int i = 0; i < dimension; i++) {
        cout << diagonal_elements[i] << " ";
    }
    cout << endl;
    
    // Reconstructing the matrix (if needed)
    cout << "Reconstructed matrix:" << endl;
    for(int i = 0; i < dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            if(i == j) {
                cout << diagonal_elements[i] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
