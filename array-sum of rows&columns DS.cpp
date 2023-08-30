#include <stdio.h>
void calculateSums(int arr[][3], int rows, int cols) {
    int rowSums[rows];
    int colSums[cols];
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
    }
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSums[i] += arr[i][j];
            colSums[j] += arr[i][j];
        }
    }
    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i + 1, rowSums[i]);
    }
    printf("Sum of each column:\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: %d\n", j + 1, colSums[j]);
    }
}

int main() {
    int arr[][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    calculateSums(arr, rows, cols);

    return 0;
}
