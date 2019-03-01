#include <stdio.h>
#include <mem.h>
#include <malloc.h>

// Find the most common word in file.txt
// You need to make sure that characters like commas, colons, etc are not part of the words.
// Also make it case sensitive so words that only different in case sensitivity are the same.

int main()
{

    /* char blabla[] = "asd fgh";
     char *sssddd = strtok(blabla, " ");

     char *name = "../inputfile.txt";
     FILE *myfile = fopen(name, "r");

     if (myfile == NULL) {
         printf("Failed to open file");
         return 0;
     }

     int ch = 0;
     int char_num = 0;
     int number_of_words = 1;
     while (!feof(myfile)) {
         ch = fgetc(myfile);
         char_num++;
         if (ch == ' ') {
             number_of_words++;
         }
     }
     fclose(myfile);

     printf("Number of words: %d\n", number_of_words);

     printf("Number of chars: %d\n", char_num);

     char *text = (char *) malloc(sizeof(char *) * char_num);
     int i = 0;
     while (!feof(myfile)) {
         text[i++] = fgetc(myfile);
     }

     char **array = (char **) malloc(sizeof(char *) * number_of_words);
     for (int i = 0; i < number_of_words; i++) {
         char *word;
         if (i == 0) {
             word = strtok(text, " ");
         } else {
             word = strtok(NULL, " ");
         }
 */
    char *index_max = NULL;
    char wl[10][10] = {"hello", "world", "goodbye", "world", "thanks", "for", "all", "hello", "the", "world"};

    int occurrence = 0;
    int maximum = 0;

    for (int i = 0; i < 10; i++) {
        occurrence = 0;
        for (int j = i; j < 10; j++) {
            if (!strcmp(*(wl + i), *(wl + j))) {
                occurrence++;
            }
        }
        if (occurrence > maximum) {
            maximum = occurrence;
            index_max = *(wl + i);
        }
    }
    if (index_max != NULL) {
        printf("The most frequent word: %s\nNumber of occurrences: %d \n", index_max, maximum);
    }

    return 0;
}

