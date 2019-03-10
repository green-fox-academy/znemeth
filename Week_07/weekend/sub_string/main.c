#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subs(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == len2) {
        return -1;
    } else if (len1 < len2) {
        if (strstr(str2, str1) != NULL) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (strstr(str1, str2) != NULL) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same length than the function should return -1

    char str1[20];
    char str2[20];
    printf("Give me two strings!\n");
    scanf("%s %s", str1, str2);
    printf("%d", subs(str1, str2));
    return 0;
}