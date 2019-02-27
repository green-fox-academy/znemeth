#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *words(char *word_first, char *word_second)
{
    int word_length = strlen(word_first) + strlen(word_second);
    char *new_word = (char *) malloc(word_length * sizeof(char));
    strcpy(new_word, word_first);
    strcat(new_word, word_second);
    return new_word;
}

int main()
{
    char *first_word = "hatata";
    char *second_word = "batata";

    words(first_word, second_word);

    printf("Your 1. word: %s \n", first_word);
    printf("Your 2. word: %s \n", second_word);
    printf("Your new word: %s \n", words(first_word, second_word));

    return 0;
}