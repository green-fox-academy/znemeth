#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file


int countlines(char *filename)
{
    char line[15];
    FILE *myfile = fopen(filename, "r");

    if (myfile == NULL) {
        printf("Failed to open file");
        return 0;
    }

    int sorokszama = 0;
    while (fgets(line, sizeof(line), myfile) != NULL) {
        //puts(line);
        //printf("%s", line);
        sorokszama++;
    }

    printf("Number of lines: %d", sorokszama);

    fclose(myfile);

}

int main()
{
    countlines("my-file.txt");
    return 0;
}