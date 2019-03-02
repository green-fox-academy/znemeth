#include <stdio.h>
#include <malloc.h>
#include <mem.h>

// Every line contains the name of the group and after a colon, the height of people in the group separated by commas
// Find the group where the median is the lowest.
// Note that the groups do not necessarily contain the same amount of people

int main()
{
    FILE *fp = fopen("inputfile.txt", "r");
/*
    if ((fp = fopen("inputfile.txt", "r")) == NULL) {
        printf("Can't open file");
        exit(1);
    }
*/
    char str_out[100][100];
    while ((getc(fp)) != EOF)
        for (int i = 0; i < 10; i++) {
            fscanf(fp, "%s\n", str_out[i]);
            //printf("%s\n", str_out[i]);
        }
/*
    printf("%s\n", str_out[1]);
    printf("%s\n", str_out[3]);
    printf("%s\n", str_out[5]);
    printf("%s\n", str_out[7]);
*/
    char *p = strtok(str_out[1], ":,");

    char *array[1000];
    int i = 0;
    while (p != NULL) {
        array[i++] = p;
        p = strtok(NULL, ":,");
    }

    for (i = 1; i < 20; ++i) {
        printf("%s\n", array[i]);
        atoi(array[i]);
    }

    //printf("%d", atoi(array[1]));


    return 0;
}