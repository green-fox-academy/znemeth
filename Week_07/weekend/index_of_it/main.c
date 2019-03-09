#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int position1(char *word, char *sentence)
{
    char *position = strstr(sentence, word);
    if (position) {
        return (int) (position - sentence);
    } else
        return -1;
}

int index_of_it(char *word, char *sentence)
{
    int flag = 0;
    char temp_word;
    char *token = strstr(sentence, word);
    double pos = token - sentence;

    for (int i = 0; i < pos; i++) {
        temp_word = sentence[i];
        if (strcmp(&temp_word, " ") == 0) {
            flag++;
        }
    }
    return flag;
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "doctor";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 6

    printf("Position (number of chars): %d \n", position1(word, sentence));
    printf("Position (number of words): %d \n", index_of_it(word, sentence));

    return 0;
}