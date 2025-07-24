//Evaluation of postfix expression using C
#include <stdio.h>      
#include <stdlib.h>     
#include <ctype.h>      
#include <string.h>     
#define MAX_SIZE 100    

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0;
}

int evaluatePostfix(char *arr[], int size) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; i < size; i++) {
        char *token = arr[i];
        
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } 
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
            if (strcmp(token, "+") == 0) {
                push(&stack, val2 + val1);
            } else if (strcmp(token, "-") == 0) {
                push(&stack, val2 - val1);
            } else if (strcmp(token, "*") == 0) {
                push(&stack, val2 * val1);
            } else if (strcmp(token, "/") == 0) {
                push(&stack, val2 / val1);
            }
        }
    }
    
    return pop(&stack);
}

int main() {
    char *arr[] = {"2", "3", "1", "*", "+", "9", "-"};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", evaluatePostfix(arr, size)); 
    return 0;
}
