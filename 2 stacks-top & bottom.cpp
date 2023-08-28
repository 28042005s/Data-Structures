#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full\n");
    } else {
        stack->items[++stack->top] = value;
    }
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->items[stack->top--];
    }
}
void printTopAndBottom(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack->items[stack->top]);
        printf("Bottom element: %d\n", stack->items[0]);
    }
}

int main() {
    struct Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);

    push(&stack2, 100);
    push(&stack2, 200);
    push(&stack2, 300);

    printf("Top and Bottom of Stack 1:\n");
    printTopAndBottom(&stack1);

    printf("\nTop and Bottom of Stack 2:\n");
    printTopAndBottom(&stack2);

    return 0;
}
