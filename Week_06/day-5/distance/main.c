#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurrence of character 's'

int main()
{
    char str[] = "This is a sample string";
    const char ch = 's';
    char *ret1;
    char *ret2;

    ret1 = strchr(str, ch);
    ret2 = strrchr(str, ch);

    printf("Distance: %d\n", ret2 - ret1 - 1);

    int count = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    printf("Length of string: %d\n", strlen(str));
    return 0;
}