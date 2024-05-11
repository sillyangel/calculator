#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int add(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    return num1 / num2;
}

int main() {
    // Print the title
    printf("Angel's Basic Calculator ");
    printf("\xC2\xA9 2024 \n");

    // Get the type of operation
    printf("Enter Type? \n");

    // Print the options
    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n");
    printf("4. Division \n");
    
    // Get User input for the type of operation
    int type; 
    scanf("%d", &type);

    // Get User input for the numbers
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform the operation and print the result
    int result;
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
        default:
            printf("Invalid operation type.\n");
            return 1;
    }
    printf("Result: %d\n", result);

    return 0;
}