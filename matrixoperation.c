
#include <stdio.h>

#define MAX 10   // Maximum size of matrix

// Function to input a matrix
void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Matrix Multiplication
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            result[i][j] = 0;
            for(int k=0; k<c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Transpose of a matrix
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    // Matrix Addition Example
    printf("Matrix Addition:\n");
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    inputMatrix(a, rows, cols);
    inputMatrix(b, rows, cols);

    addMatrix(a, b, result, rows, cols);
    printf("Result of Addition:\n");
    displayMatrix(result, rows, cols);

    // Matrix Multiplication Example
    int r1, c1, r2, c2;
    printf("\nMatrix Multiplication:\n");
    printf("Enter rows and cols of first matrix: ");
    scanf("%d %d", &r1, &c1);
    inputMatrix(a, r1, c1);

    printf("Enter rows and cols of second matrix: ");
    scanf("%d %d", &r2, &c2);
    inputMatrix(b, r2, c2);

    if(c1 != r2) {
        printf("Matrix multiplication not possible!\n");
    } else {
        multiplyMatrix(a, b, result, r1, c1, c2);
        printf("Result of Multiplication:\n");
        displayMatrix(result, r1, c2);
    }

    // Transpose Example
    printf("\nTranspose:\n");
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);
    inputMatrix(a, rows, cols);

    transposeMatrix(a, result, rows, cols);
    printf("Transpose of Matrix:\n");
    displayMatrix(result, cols, rows);

    return 0;
}
