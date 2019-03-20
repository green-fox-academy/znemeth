#include <stdio.h>
#include <mem.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("inputfile.txt", "r");
    char buffer[1000][1000];
    int i = 0;
    while (fgets(buffer[i], sizeof(buffer), fp)) {
        buffer[i++];
    }
    fclose(fp);

    //-----------------------------------------------
    char *p1 = strtok(buffer[1], " ");
    char *array1[1000];
    int j = 0;
    while (p1 != NULL) {
        array1[j++] = p1;
        p1 = strtok(NULL, " ");
    }

    char *p2 = strtok(buffer[2], " ");
    char *array2[1000];
    int k = 0;
    while (p2 != NULL) {
        array2[k++] = p2;
        p2 = strtok(NULL, " ");
    }

    char *p3 = strtok(buffer[3], " ");
    char *array3[1000];
    int l = 0;
    while (p3 != NULL) {
        array3[l++] = p3;
        p3 = strtok(NULL, " ");
    }
    //-----------------------------------------------
    int in1 = 0;
    for (int q = 0; q < 100; ++q) {
        if (atoi(array1[q]) == 1) {
            in1++;
        }
    }

    int in2 = 0;
    for (int r = 0; r < 100; ++r) {
        if (atoi(array2[r]) == 1) {
            in2++;
        }
    }

    int in3 = 0;
    for (int r = 0; r < 100; ++r) {
        if (atoi(array3[r]) == 1) {
            in3++;
        }
    }

    printf("Number of incoming customers between 06:00-07:00: %d\n", in1);
    printf("Number of incoming customers between 07:00-08:00: %d\n", in2);
    printf("Number of incoming customers between 08:00-09:00: %d\n", in3);

    int max_array[3] = {in1, in2, in3};
    int a;
    int size = 3;
    int maximum;

    maximum = max_array[0];

    for (a = 0; a < size; a++) {
        if (max_array[a] > maximum) {
            maximum = max_array[a];
        }
    }

    printf("Max number: %d", maximum);
    return 0;
}