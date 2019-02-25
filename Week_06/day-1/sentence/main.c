#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

char *slicer(char sent[256])
{
    char *token;
    token = strtok(sent, " ");

    while (token != NULL) {
        printf(" %s\n", token);
        token = strtok(NULL, " ");
    }
}

int main()
{
    printf("Type in a sentence:\n");
    char sent[256];
    gets(sent);

    puts(slicer(sent));

    return (0);
}