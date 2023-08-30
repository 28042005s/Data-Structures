#include <stdio.h>
void findMostFrequent(int arr[], int size) {
    int maxCount = 0;
    int mostFrequent = arr[0];

    for (int i = 0; i < size; i++) {
        int count = 1;

        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    printf("The most frequently repeated element is %d\n", mostFrequent);
    printf("It appears %d times\n", maxCount);
}

int main() {
    int arr[] = {3, 4, 2, 4, 2, 4, 3, 5, 4, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMostFrequent(arr, size);

    return 0;
}
