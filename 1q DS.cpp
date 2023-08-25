#include <stdio.h>
#include <limits.h>
int reverse(int x) {
    int int_MAX = 2147483647;
    int int_MIN = -2147483648;
    
    int reversed = 0;
    while (x != 0) {
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10) {
            return 0;
        }
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    return reversed;
}
int main() {
    int num1 = 123;
    int num2 = -456;
    int num3 = 1534236469;
    printf("%d\n", reverse(num1)); 
    printf("%d\n", reverse(num2)); 
    printf("%d\n", reverse(num3)); 
    
    return 0;
}
