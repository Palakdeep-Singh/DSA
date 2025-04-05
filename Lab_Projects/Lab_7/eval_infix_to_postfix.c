#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int valStack[MAX], topVal = -1;
char opStack[MAX], topOp = -1;

// Stack operations for values and operators
void pushVal(int val) {
    valStack[++topVal] = val;
}

int popVal() {
    return valStack[topVal--];
}

void pushOp(char op) {
    opStack[++topOp] = op;
}

char popOp() {
    return opStack[topOp--];
}

char peekOp() {
    return opStack[topOp];
}

// Check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if operator is right-associative
int isRightAssociative(char op) {
    return op == '^';
}

// Apply operator to operands
int applyOp(int a, int b, char op) {
    int result = 0;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = b != 0 ? a / b : 0; break;
        case '^':
            result = 1;
            for (int i = 0; i < b; i++) result *= a;
            break;
    }
    return result;
}

// Evaluate infix expression
int evaluate(char expr[]) {

    int i = 0;

    while (expr[i] != '\0' && expr[i] != '\n') {
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        // Read number (multi-digit)
        if (isDigit(expr[i])) {

            int num = 0;
            while (isDigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            pushVal(num);
        }
        else if (expr[i] == '(') {

            pushOp(expr[i]);
            i++;

        }
        else if (expr[i] == ')') {
            while (topOp != -1 && peekOp() != '(') {

                int b = popVal();
                int a = popVal();
                char op = popOp();

                pushVal(applyOp(a, b, op));
            }
            popOp(); // remove '('
            i++;
        }
        else { // Operator
            while (topOp != -1 && peekOp() != '(' &&(precedence(peekOp()) > precedence(expr[i]) || (precedence(peekOp()) == precedence(expr[i]) && !isRightAssociative(expr[i])))) {

                int b = popVal();
                int a = popVal();
                char op = popOp();

                pushVal(applyOp(a, b, op));
            }
            pushOp(expr[i]);
            i++;
        }
    }

    while (topOp != -1) {

        int b = popVal();

        int a = popVal();

        char op = popOp();

        pushVal(applyOp(a, b, op));
    }

    return popVal();
}

int main() {
    char expr[MAX];

    printf("Enter infix expression: ");
    fgets(expr, sizeof(expr), stdin);

    int result = evaluate(expr);
    printf("Result: %d\n", result);

    return 0;
}
