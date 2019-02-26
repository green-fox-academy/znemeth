#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    char line[15];
    FILE *myfile = fopen("my-file.txt", "r");

    if (myfile == NULL) {
        printf("Failed to open file");
        return 1;
    }

    while (fgets(line, sizeof(line), myfile) != NULL) {
        //puts(line);
        printf("%s", line);
    }

    fclose(myfile);

    return 0;
}