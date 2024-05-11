#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator

    int num1 = rand() % 10; // Generate a random number between 0 and 9
    int num2 = rand() % 10;
    int answer, userAnswer;

    printf("Welcome to the Math Game!\n");
    printf("What is the result of %d + %d?\n", num1, num2);
    scanf("%d", &userAnswer);

    answer = num1 + num2;

    if (userAnswer == answer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Oops! Your answer is incorrect. The correct answer is %d.\n", answer);
    }

    return 0;
}