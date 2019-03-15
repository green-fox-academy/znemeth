#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "string.h"

int main()
{
    FILE *fp;
    FILE *fout;
    int count = 0;
    char file_content[3000];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
        return (-1);
    } else if (fp != NULL) {
        fgets(file_content, 3000, fp);
        //puts(file_content);
    }
    fclose(fp);

    char *temp = strtok(file_content, " ");
    char *binary[3000];
    int i = 0;
    while (temp != NULL) {
        binary[i++] = temp;
        temp = strtok(NULL, " ");
        count++;
    }

    printf("Number of characters: %d\n\n", count);

    fout = fopen("output.txt", "w");

    char *ptr;
    long ret;

    for (int j = 0; j < 140; ++j) {
        ret = strtol(&binary[j][0], &ptr, 2);
        fprintf(fout, "%c", ret);
    }

    fclose(fout);
    return 0;
}