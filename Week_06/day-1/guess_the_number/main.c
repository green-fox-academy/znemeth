#include <stdio.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8

    int number;
    int numberSet = 56;
    printf("Guess the number between 1 and 100!\n");
    printf("You have 10 lives!\n");

    for (int i = 10; i > 0; i--) {
        printf("Guess a number!\n");
        scanf("%d", &number);

        if (number < numberSet) {
            printf("The stored number is higher\n");
        } else if (number > numberSet) {
            printf("The stored number is lower\n");
        } else if (number == numberSet) {
            printf("You win!\n");
            break;
        }
    }
    return 0;
}