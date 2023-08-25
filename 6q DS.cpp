#include <stdio.h>
int searchRegNo(int regNos[], int size, int targetRegNo) {
    for (int i = 0; i < size; i++) {
        if (regNos[i] == targetRegNo) {
            return i;  
        }
    }
    return -1;  
}
int main() {
    int size;
    printf("Enter the number of registration numbers: ");
    scanf("%d", &size);
    int regNos[size];
    printf("Enter the registration numbers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &regNos[i]);
    }
    int targetRegNo;
    printf("Enter the registration number to search for: ");
    scanf("%d", &targetRegNo);
    int index = searchRegNo(regNos, size, targetRegNo);
    if (index != -1) {
        printf("Registration number %d found at index %d.\n", targetRegNo, index);
    } else {
        printf("Registration number %d not found.\n", targetRegNo);
    }
    return 0;
}
