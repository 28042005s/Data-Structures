#include <stdio.h>

int main() {
    int array[10] = {5, 12, 9, 6, 3, 7, 15, 8, 10, 1};
    int evenCount = 0, oddCount = 0;

    printf("Even values in the array: ");
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 == 0) {
            printf("%d ", array[i]);
            evenCount++;
        }
    }
    printf("\nTotal even values: %d\n", evenCount);

    printf("Odd values in the array: ");
    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 != 0) {
            printf("%d ", array[i]);
            oddCount++;
        }
    }
    printf("\nTotal odd values: %d\n", oddCount);

    return 0;
}
