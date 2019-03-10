#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeat(char *word, int number)
{
    char *pointer;
    pointer = (char*) malloc(25 * sizeof(char));
    for (int i = 0; i < number; i++) {
        strcat(pointer, word);
    }
    return pointer;
}

int main()
{
    char *rep = repeat("Apple", 5);
    printf("%s", rep);
    free(rep);
    return 0;
}