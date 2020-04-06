#define swap(a, b) {\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixColSize[i]; j++) {
            if (i == j) continue;
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < (matrixColSize[i] / 2); j++) {        
            swap(matrix[i][matrixColSize[i] - 1 - j], matrix[i][j]);
        }
    }
}
