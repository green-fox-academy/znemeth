#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"


void writing_files(char *na, char *w, int n)
{
    FILE *myfile = fopen(na, "w");
    for (int i = 0; i < n; i++) {
        fputs(w, myfile);
    }

    fclose(myfile);
}

int main()
{

    char *name = "../my-file.txt";

    char word [7] = "apple";
    char *pause = "\n";

    strcat(word, pause);

    int number = 5;

    writing_files(name, word, number);

    return 0;
}