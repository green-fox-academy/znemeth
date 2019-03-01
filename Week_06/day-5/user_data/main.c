#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main()
{
    printf(__DATE__ " " __TIME__"\n");
    char text[100];
    puts("Gimme your full name and age!\n");
    gets(text);
    //printf("Your input: %s", text);

    char fname[20];
    char sname[20];
    char age[10];

    strcpy(fname, strtok(text, " "));
    strcpy(sname, strtok(NULL, " "));
    strcpy(age, strtok(NULL, " "));

    int val = atoi(age);
    printf("Your name is: %s %s and you are %d years old", fname, sname, val);

    return 0;
}