#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *append(char *string)
{
    char * res;
    char * letter = "AAA";
    res = strcat(string, letter);
    return res;
}

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    puts("Gimme string: ");
    char string[200];
    gets(string);
    puts(append(string));

    return 0;
}