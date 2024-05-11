#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_operations.h"


double power(double num1, double num2) {
    return pow(num1, num2);
}

double square_root(double num1) {
    if (num1 >= 0.0) {
        return sqrt(num1);
    } else {
        printf("Error: Square root of negative number is not allowed.\n");
        return NAN;
    }
}

double sine(double num1) {
    return sin(num1);
}

double cosine(double num1) {
    return cos(num1);
}

double tangent(double num1) {
    return tan(num1);
}

int main() {
    // Print the title
    printf("\nAngel's Calculator ");
    printf("\xC2\xA9 2024 \n \n");

    // Get the type of operation
    printf("Enter Type? \n");

    // Print the options
    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n");
    printf("4. Division \n");
    printf("5. Power \n");
    printf("6. Square Root \n");
    printf("7. Sine \n");
    printf("8. Cosine \n");
    printf("9. Tangent \n \n");
    
    // Get User input for the type of operation
    int type; 
    printf("Enter operation type: ");
    scanf("%d", &type);

    // Print "selected operation"
    printf("\nSelected operation: ");
    const char* operations[] = {
        "Invalid operation type",
        "Addition",
        "Subtraction",
        "Multiplication",
        "Division",
        "Power",
        "Square Root",
        "Sine",
        "Cosine",
        "Tangent"
    };
    
    if (type < 1 || type > 9) {
        type = 0; // Set to 0 for invalid operation type
    }

    printf("%s\n", operations[type]);

    if (type == 0) {
        return 1;
    }
    printf("\n"); 

    // Get User input for the numbers
    double num1, num2;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    if (type != 6 && type != 7 && type != 8 && type != 9) {
        printf("Enter second number: ");
        scanf("%lf", &num2);
    }

    // Perform the operation and print the result
    double result;
    switch(type) {
        case 1:
            result = add(num1, num2);
            break;
        case 2:
            result = sub(num1, num2);
            break;
        case 3:
            result = mul(num1, num2);
            break;
        case 4:
            result = divide(num1, num2);
            break;
        case 5:
            result = power(num1, num2);
            break;
        case 6:
            result = square_root(num1);
            break;
        case 7:
            result = sine(num1);
            break;
        case 8:
            result = cosine(num1);
            break;
        case 9:
            result = tangent(num1);
            break;
        default:
            printf("Invalid operation type.\n");
            return 1;
    }
    printf("\n");
    printf("Result: %.2lf\n", result);

    return 0;
}