#include <stdio.h>

int main() {
    int array[10] = {5, 12, 9, 6, 3, 7, 15, 8, 10, 1};
    int elementToSearch, found = 0;

    printf("Enter the element to search for: ");
    scanf("%d", &elementToSearch);

    for (int i = 0; i < 10; i++) {
        if (array[i] == elementToSearch) {
            printf("Element %d found at index %d.\n", elementToSearch, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", elementToSearch);
    }

    return 0;
}
