#include "math_operations.h"
#include <math.h>
#include <stdio.h>

double add(double num1, double num2) {
    return num1 + num2;
}

double sub(double num1, double num2) {
    return num1 - num2;
}

double mul(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0.0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return NAN;
    }
}