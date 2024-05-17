#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator

    int num1, num2, answer, userAnswer;
    char operation;
    int correct = 1; // Flag to check if the answer is correct
    int level = 1; // Level counter
    int equationCount = 0; // Equation counter

    printf("Welcome to the Math Game!\n");

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    while(correct) {
        int range = 10 + (equationCount / 10) * 10; // Increase the range every 10 equations
        num1 = rand() % range; // Generate a random number within the range
        num2 = rand() % range;
        int operationIndex = rand() % 4; // Generate a random number between 0 and 3

        switch(operationIndex) {
            case 0: // Addition
                operation = '+';
                answer = num1 + num2;
                break;
            case 1: // Subtraction
                operation = '-';
                answer = num1 - num2;
                break;
            case 2: // Multiplication
                operation = '*';
                answer = num1 * num2;
                break;
            case 3: // Division
                operation = '/';
                answer = num1 / num2;
                break;
        }

        printf("Level %d: What is the result of %d %c %d?\n", level, num1, operation, num2);
        scanf("%d", &userAnswer);

        if (userAnswer == answer) {
            printf("Congratulations! Your answer is correct.\n");
            level++; // Increment the level counter
            equationCount++; // Increment the equation counter
        } else {
            printf("Oops! Your answer is incorrect. The correct answer is %d.\n", answer);
            correct = 0; // Set the flag to false to exit the loop
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("You reached level %d and played for %f seconds.\n", level - 1, cpu_time_used);

    return 0;
}