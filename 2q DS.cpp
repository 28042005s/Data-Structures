#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
bool isValidString(const char *str) {
    int length = strlen(str);
    
    if (length < 1 || length > 100) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    
    return true;
}
int main() {
    char input[101]; 
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    if (isValidString(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }
    
    return 0;
}
