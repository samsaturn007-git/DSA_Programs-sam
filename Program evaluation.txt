#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Define the stack data structure
struct Stack {
    int top;
    double items[MAX_STACK_SIZE];
};

// Initialize an empty stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an item onto the stack
void push(struct Stack *s, double value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = value;
}

// Pop an item from the stack
double pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to evaluate an arithmetic expression
double evaluateExpression(const char *expression) {
    struct Stack operandStack;
    initialize(&operandStack);

    struct Stack operatorStack;
    initialize(&operatorStack);

    int i = 0;
    while (expression[i] != '\0') {
        if (isspace(expression[i])) {
            i++; // Skip white spaces
            continue;
        }
        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || expression[i - 1] == '('))) {
            // If the current character is a digit or a negative sign at the beginning of a number
            double operand = 0;
            while (isdigit(expression[i]) || expression[i] == '.') {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            push(&operandStack, operand);
        } else if (expression[i] == '(') {
            // If the current character is an open parenthesis, push it onto the operator stack
            push(&operatorStack, expression[i]);
            i++;
        } else if (expression[i] == ')') {
            // If the current character is a closing parenthesis, pop and evaluate operators
            // until an open parenthesis is encountered
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                char op = operatorStack.items[operatorStack.top];
                pop(&operatorStack);
                double operand2 = pop(&operandStack);
                double operand1 = pop(&operandStack);
                if (op == '+') {
                    push(&operandStack, operand1 + operand2);
                } else if (op == '-') {
                    push(&operandStack, operand1 - operand2);
                } else if (op == '*') {
                    push(&operandStack, operand1 * operand2);
                } else if (op == '/') {
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    push(&operandStack, operand1 / operand2);
                }
            }
            if (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] == '(') {
                pop(&operatorStack); // Pop the open parenthesis
            } else {
                printf("Mismatched parentheses.\n");
                exit(1);
            }
            i++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // If the current character is an operator
            while (!isEmpty(&operatorStack) &&
                   (operatorStack.items[operatorStack.top] == '+' || operatorStack.items[operatorStack.top] == '-' ||
                    operatorStack.items[operatorStack.top] == '*' || operatorStack.items[operatorStack.top] == '/') &&
                   ((expression[i] == '+' || expression[i] == '-') ||
                    (expression[i] == '*' || expression[i] == '/') && (operatorStack.items[operatorStack.top] == '*' || operatorStack.items[operatorStack.top] == '/'))) {
                char op = operatorStack.items[operatorStack.top];
                pop(&operatorStack);
                double operand2 = pop(&operandStack);
                double operand1 = pop(&operandStack);
                if (op == '+') {
                    push(&operandStack, operand1 + operand2);
                } else if (op == '-') {
                    push(&operandStack, operand1 - operand2);
                } else if (op == '*') {
                    push(&operandStack, operand1 * operand2);
                } else if (op == '/') {
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    push(&operandStack, operand1 / operand2);
                }
            }
            push(&operatorStack, expression[i]);
            i++;
        } else {
            printf("Invalid character in the expression: %c\n", expression[i]);
            exit(1);
        }
    }

    // Pop and evaluate any remaining operators
    while (!isEmpty(&operatorStack)) {
        char op = operatorStack.items[operatorStack.top];
        pop(&operatorStack);
        double operand2 = pop(&operandStack);
        double operand1 = pop(&operandStack);
        if (op == '+') {
            push(&operandStack, operand1 + operand2);
        } else if (op == '-') {
            push(&operandStack, operand1 - operand2);
        } else if (op == '*') {
            push(&operandStack, operand1 * operand2);
        } else if (op == '/') {
            if (operand2 == 0) {
                printf("Division by zero is not allowed.\n");
                exit(1);
            }
            push(&operandStack, operand1 / operand2);
        }
    }

    // The result should be the only item left on the operand stack
    if (isEmpty(&operandStack) || operandStack.top != 0) {
        printf("Invalid expression.\n");
        exit(1);
    }

    return operandStack.items[operandStack.top];
}

int main() {
    char expression[100];
    printf("Enter an arithmetic expression: ");
    scanf("%99[^\n]", expression);

    double result = evaluateExpression(expression);
    printf("Result: %lf\n", result);

    return 0;
}
