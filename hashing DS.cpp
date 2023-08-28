#include <stdio.h>
#include <string.h>
#define HASH_SIZE 100
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (*str);
        str++;
    }
    return hash % HASH_SIZE;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 
    unsigned int hashedValue = hash(input);
    printf("Hashed value: %u\n", hashedValue);
    return 0;
}
