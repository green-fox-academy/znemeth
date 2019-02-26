#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main()
{
    FILE *myfile = fopen("../my-file.txt", "w");
    char *ilnome = "Io sono Zoltan Nemeth, il dottore di chimica ambientale.";
    fputs(ilnome, myfile);

    fclose(myfile);

    return 0;
}