#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a stack structure
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, char c);
char pop(Stack *s);
int precedence(char c);
void infixToPostfix(char *infix, char *postfix);

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to push element onto stack
void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

// Function to pop element from stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to determine precedence of operators
int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack stack;
    stack.top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Discard '('
        } else { // Operator
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    // Pop remaining operators from stack
    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null terminate the string
}
