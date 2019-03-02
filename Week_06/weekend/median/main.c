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

    printf("%s\n", str_out[1]);
    printf("%s\n", str_out[3]);
    printf("%s\n", str_out[5]);
    printf("%s\n", str_out[7]);

    for (char *p = strtok(str_out[1], ":,"); p != NULL; p = strtok(NULL, ",")) {
        printf("%s ", p);
    }
    return 0;
}