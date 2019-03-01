#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

int main()
{
    char string[55] = "This is a string for testing";
    //char *p;
    char letter = 'i';

    for (int i = 0; i < 55; i++) {
        //printf("Positions: ");
        if (string[i] == letter) {

            printf("%d ", i);
        }
    }

    return 0;
}