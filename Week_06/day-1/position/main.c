#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

int main()
{
    char string[55] = "This is a string for testing";
    char *p;
    char letter = 'i';

    for (char *p = strtok(string, "i"); p != NULL; p = strtok(NULL, "i")) {
        puts(p);
    }

    for (int j = 0; j < (sizeof(string) / sizeof(string[0])); j++) {
        int count = 0;
        if (string[j] == letter) {
            count++;
        }
    }
    return 0;
}