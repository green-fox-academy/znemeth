#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char firstWord[100];
    char secondWord[100];

    printf("1. word: \n");
    scanf("%s", firstWord);

    printf("2. word: \n");
    scanf("%s", secondWord);

    int temp;
    if (strcmp(firstWord, secondWord) == 0) {
        temp = 1;
    } else {
        temp = 0;
    }

    printf("Length: %d", temp);
}