#include <stdio.h>
void findDuplicates(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate element: %d\n", arr[i]);
                break;
            }
        }
    }
}
int main() {
    int arr[] = {3, 7, 2, 8, 3, 9, 1, 7, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Duplicate elements in the array:\n");
    findDuplicates(arr, size);
    return 0;
}
