#include<iostream>
using namespace std;

void ShowMatrix(int (&matrix)[][3], int rows){
    for(int row_idx = 0; row_idx < rows; row_idx++){
        for(int col_idx = 0; col_idx < 3; col_idx++){
            cout << matrix[row_idx][col_idx] << "\t";
        }
        cout << endl;
    }
}

void ExchangeValues(int &first, int &second){
    int temporary = first;
    first = second;
    second = temporary;
}

void ArrangeMatrix(int (&matrix)[][3], int element_count) {
    for (int i = 1; i < element_count - 1; i++) {
        for (int j = i + 1; j < element_count; j++) {
            if (matrix[i][0] > matrix[j][0] ||
               (matrix[i][0] == matrix[j][0] && matrix[i][1] > matrix[j][1])) {
                for (int k = 0; k < 3; k++) {
                    ExchangeValues(matrix[i][k], matrix[j][k]);
                }
            }
        }
    }
}

void ComputeTranspose(int (&source)[][3], int (&destination)[][3], int size) {
    destination[0][0] = source[0][1];
    destination[0][1] = source[0][0];
    destination[0][2] = source[0][2];

    for (int idx = 1; idx < size; idx++) {
        destination[idx][0] = source[idx][1];
        destination[idx][1] = source[idx][0];
        destination[idx][2] = source[idx][2];
    }

    ArrangeMatrix(destination, size);
}

void MatrixAddition(int (&matrixA)[][3], int (&matrixB)[][3], int (&result)[][3]) {
    int row_count = matrixA[0][0], col_count = matrixA[0][1];
    int idxA = 1, idxB = 1, idxRes = 1;
    int nonZeroA = matrixA[0][2], nonZeroB = matrixB[0][2];

    result[0][0] = row_count;
    result[0][1] = col_count;

    while (idxA <= nonZeroA && idxB <= nonZeroB) {
        if (matrixA[idxA][0] == matrixB[idxB][0] && matrixA[idxA][1] == matrixB[idxB][1]) {
            int total = matrixA[idxA][2] + matrixB[idxB][2];
            if (total != 0) {
                result[idxRes][0] = matrixA[idxA][0];
                result[idxRes][1] = matrixA[idxA][1];
                result[idxRes][2] = total;
                idxRes++;
            }
            idxA++;
            idxB++;
        }
        else if (matrixA[idxA][0] < matrixB[idxB][0] || 
                (matrixA[idxA][0] == matrixB[idxB][0] && matrixA[idxA][1] < matrixB[idxB][1])) {
            result[idxRes][0] = matrixA[idxA][0];
            result[idxRes][1] = matrixA[idxA][1];
            result[idxRes][2] = matrixA[idxA][2];
            idxRes++;
            idxA++;
        }
        else {
            result[idxRes][0] = matrixB[idxB][0];
            result[idxRes][1] = matrixB[idxB][1];
            result[idxRes][2] = matrixB[idxB][2];
            idxRes++;
            idxB++;
        }
    }

    while (idxA <= nonZeroA) {
        result[idxRes][0] = matrixA[idxA][0];
        result[idxRes][1] = matrixA[idxA][1];
        result[idxRes][2] = matrixA[idxA][2];
        idxRes++;
        idxA++;
    }

    while (idxB <= nonZeroB) {
        result[idxRes][0] = matrixB[idxB][0];
        result[idxRes][1] = matrixB[idxB][1];
        result[idxRes][2] = matrixB[idxB][2];
        idxRes++;
        idxB++;
    }

    result[0][2] = idxRes - 1;
}

void MatrixMultiplication(int (&matrixX)[][3], int (&matrixY)[][3], int (&product)[][3]) {
    if (matrixX[0][1] != matrixY[0][0]) {
        cout << "Matrix dimensions incompatible for multiplication!\n";
        product[0][2] = 0;
        return;
    }

    int transposedY[matrixY[0][2]+1][3];
    ComputeTranspose(matrixY, transposedY, matrixY[0][2]+1);

    product[0][0] = matrixX[0][0];
    product[0][1] = matrixY[0][1];
    int result_idx = 1;

    int rowStartX = 1;
    while (rowStartX <= matrixX[0][2]) {
        int current_rowX = matrixX[rowStartX][0];

        int rowEndX = rowStartX;
        while (rowEndX <= matrixX[0][2] && matrixX[rowEndX][0] == current_rowX)
            rowEndX++;

        int rowStartT = 1;
        while (rowStartT <= transposedY[0][2]) {
            int current_rowT = transposedY[rowStartT][0];

            int rowEndT = rowStartT;
            while (rowEndT <= transposedY[0][2] && transposedY[rowEndT][0] == current_rowT)
                rowEndT++;

            int i = rowStartX;
            int j = rowStartT;
            int dot_product = 0;

            while (i < rowEndX && j < rowEndT) {
                if (matrixX[i][1] == transposedY[j][1]) {
                    dot_product += matrixX[i][2] * transposedY[j][2];
                    i++; j++;
                }
                else if (matrixX[i][1] < transposedY[j][1]) {
                    i++;
                }
                else {
                    j++;
                }
            }

            if (dot_product != 0) {
                product[result_idx][0] = current_rowX;
                product[result_idx][1] = current_rowT;
                product[result_idx][2] = dot_product;
                result_idx++;
            }

            rowStartT = rowEndT;
        }

        rowStartX = rowEndX;
    }

    product[0][2] = result_idx - 1;
}

int main()
{
  int original_matrix[4][4] = {{0,8,9,0}, {3,0,0,1}, {0,0,7,0}, {2,4,5,0}};
  int second_matrix[4][4] = {{1,9,0,0}, {7,0,0,2}, {0,8,9,0}, {0,0,0,3}};
  
  int dimension = sizeof(original_matrix)/sizeof(original_matrix[0]);
  
  int non_zero_count = 0;
  for(int i = 0; i < dimension; i++){
      for(int j = 0; j < dimension; j++){
          if(original_matrix[i][j] != 0){
              non_zero_count++;
          }
      }
  }
  
  int sparse_matrix[non_zero_count+1][3];
  sparse_matrix[0][0] = dimension;
  sparse_matrix[0][1] = dimension;
  sparse_matrix[0][2] = non_zero_count;
  
  int position = 1;
  for(int i = 0; i < dimension; i++){
      for(int j = 0; j < dimension; j++){
          if(original_matrix[i][j] != 0){
              sparse_matrix[position][0] = i;
              sparse_matrix[position][1] = j;
              sparse_matrix[position][2] = original_matrix[i][j];
              position++;
          }
      }
  }
  
  int non_zero_count2 = 0;
  for(int i = 0; i < dimension; i++){
      for(int j = 0; j < dimension; j++){
          if(second_matrix[i][j] != 0){
              non_zero_count2++;
          }
      }
  }
  
  int sparse_matrix2[non_zero_count2+1][3];
  sparse_matrix2[0][0] = dimension;
  sparse_matrix2[0][1] = dimension;
  sparse_matrix2[0][2] = non_zero_count2;
  
  position = 1;
  for(int i = 0; i < dimension; i++){
      for(int j = 0; j < dimension; j++){
          if(second_matrix[i][j] != 0){
              sparse_matrix2[position][0] = i;
              sparse_matrix2[position][1] = j;
              sparse_matrix2[position][2] = second_matrix[i][j];
              position++;
          }
      }
  }
  
  int transpose_result[non_zero_count+1][3];
  
  cout << "Original Sparse Matrix:" << endl;
  ShowMatrix(sparse_matrix, non_zero_count+1);
  cout << endl << "Transposed Matrix:" << endl;
  ComputeTranspose(sparse_matrix, transpose_result, non_zero_count+1);
  ShowMatrix(transpose_result, non_zero_count+1);
  
  int addition_result[50][3];
  cout << endl << "Matrix Addition Result:" << endl;
  MatrixAddition(sparse_matrix, sparse_matrix2, addition_result);
  ShowMatrix(addition_result, addition_result[0][2]+1);
  
  int multiplication_result[50][3];
  cout << endl << "Matrix Multiplication Result:" << endl;
  MatrixMultiplication(sparse_matrix, sparse_matrix2, multiplication_result);
  ShowMatrix(multiplication_result, multiplication_result[0][2]+1);

  return 0;
}