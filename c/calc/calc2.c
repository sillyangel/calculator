#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack for numbers
double stack[512];
int stackPos = 0;

// Stack for operators
char opStack[512];
int opStackPos = 0;

void push(double num) {
    stack[stackPos++] = num;
}

double pop() {
    return stack[--stackPos];
}

void pushOp(char op) {
    opStack[opStackPos++] = op;
}

char popOp() {
    return opStack[--opStackPos];
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

double calculate(double num1, double num2, char op) {
    switch(op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0;
    }
}

double evaluate(char* equation) {
    char* token = strtok(equation, " ");
    while(token != NULL) {
        if(isdigit(token[0])) {
            push(atof(token));
        } else {
            while(opStackPos > 0 && precedence(opStack[opStackPos - 1]) >= precedence(token[0])) {
                double num2 = pop();
                double num1 = pop();
                char op = popOp();
                push(calculate(num1, num2, op));
            }
            pushOp(token[0]);
        }
        token = strtok(NULL, " ");
    }

    while(opStackPos > 0) {
        double num2 = pop();
        double num1 = pop();
        char op = popOp();
        push(calculate(num1, num2, op));
    }

    return pop();
}

int main() {
    char equation[256];
    printf("Enter an equation: ");
    fgets(equation, 256, stdin);
    equation[strcspn(equation, "\n")] = 0;  // Remove trailing newline
    printf("Result: %.2lf\n", evaluate(equation));
    return 0;
}