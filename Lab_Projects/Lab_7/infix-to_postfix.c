#include <stdio.h>
#include <string.h>

#define MAX 100 //stack size.

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

// Check if character is an operand (letter or digit)
int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Precedence of operators
int precedence(char op) {
    if (op == '^') return 3;

    if (op == '*' || op == '/') return 2;

    if (op == '+' || op == '-') return 1;

    return 0;
}

// Check if operator is right-associative
int isRightAssociative(char op) {
    return op == '^';
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix[j++] = c;
        } 

        else if (c == '(') {
            push(c);
        } 

        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } 
        else {      // operator        
            while (top != -1 && peek() != '(' && (precedence(peek()) > precedence(c) ||  (precedence(peek()) == precedence(c) && !isRightAssociative(c)))) {
                postfix[j++] = pop(); //add in expression
            }
            push(c);   //then push
        }
    }

    // Pop any remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
