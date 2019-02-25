#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nameLength(char *name)
{
    int a;
    a = strlen(name);
    return a;
}

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions

    char name[20];
    printf("Your name: \n");
    scanf("%s", name);

    printf("Wow your name is %d characters long.", nameLength(name));

    return 0;
}