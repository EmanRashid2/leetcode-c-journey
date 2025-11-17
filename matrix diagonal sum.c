#include <stdio.h>

int diagonalSum(int mat[][100], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += mat[i][i];                  // primary diagonal
        if(i != n - 1 - i)                 // avoid double-count
            sum += mat[i][n - 1 - i];     // secondary diagonal
    }
    return sum;
}

int main() {
    int mat[100][100];
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int result = diagonalSum(mat, n);
    printf("Sum of diagonals: %d\n", result);

    return 0;
}
