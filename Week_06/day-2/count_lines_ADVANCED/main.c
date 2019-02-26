#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file


int countlines(char *filename)
{
    //char line[15];
    FILE *myfile = fopen(filename, "r");

    if (myfile == NULL) {
        printf("Failed to open file");
        return 0;
    }

    int sorokszama = 1;
    int ch = 0;

    while (!feof(myfile)) {
        ch = fgetc(myfile);
        if (ch == '\n') {
            sorokszama++;
        }
    }

    fclose(myfile);

    return sorokszama;
}

int main()
{
    countlines("my-file.txt");
    printf("Number of line: %d", countlines("my-file.txt"));
    return 0;
}