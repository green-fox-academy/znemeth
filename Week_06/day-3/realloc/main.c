#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int *pointer = NULL;
    int number;

    printf("Enter a number: \n");
    scanf("%d", &number);

    pointer = (int *) malloc(number * sizeof(int));

    //printf("Enter %d numbers: \n", number);

    for (int j = 0; j < number; j++) {
        printf("Enter a number: \n");
        scanf("%d", &pointer[j]);
    }

    int total = 0;
    for (int i = 0; i < number; i++) {
        total += pointer[i];
    }
    printf("The sum of your numbers: %d \n", total);

    realloc(pointer, total * sizeof(int));

    for (int i = 0; i < total; i++) {
        pointer[i] = i;
    }

    for (int i = 0; i < total; i++) {
        printf("%d ", pointer[i] + 1);
    }

    return 0;
}