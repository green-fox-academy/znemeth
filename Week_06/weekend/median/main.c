#include <stdio.h>
#include <malloc.h>
#include <mem.h>

// Every line contains the name of the group and after a colon, the height of people in the group separated by commas
// Find the group where the median is the lowest.
// Note that the groups do not necessarily contain the same amount of people

int cmpfunc(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int main()
{
    FILE *fp = fopen("inputfile.txt", "r");

/*    if ((fp = fopen("inputfile.txt", "r")) == NULL) {
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
//--------------------------------------------------------
    char *p1 = strtok(str_out[1], ":,");
    char *array1[1000];
    int i = 0;
    while (p1 != NULL) {
        array1[i++] = p1;
        p1 = strtok(NULL, ":,");
    }

    int sum1 = 0;
    int count1 = 0;
    int piece1[14];
    for (i = 1; i < 15; ++i) {
        piece1[i] = atoi(array1[i]);
        sum1 += piece1[i];
        count1++;
    }
    printf("%s%d, %s%d \n", "Group A: count: ", count1, "sum: ", sum1);

    for (int i = 1; i < 15; ++i) {
        printf("%d\n", piece1[i]);
    }

    //------------------------------------------------------------------

    char *p2 = strtok(str_out[3], ":,");
    char *array2[1000];
    int j = 0;
    while (p2 != NULL) {
        array2[j++] = p2;
        p2 = strtok(NULL, ":,");
    }

    int sum2 = 0;
    int count2 = 0;
    int piece2[12];
    for (j = 1; j < 13; ++j) {
        piece2[j] = atoi(array2[j]);
        sum2 += piece2[j];
        count2++;
    }
    printf("%s%d, %s%d \n", "Group B: count: ", count2, "sum: ", sum2);

    for (int j = 1; j < 13; ++j) {
        printf("%d\n", piece2[j]);
    }

    //---------------------------------------------------------------------------

    char *p3 = strtok(str_out[5], ":,");
    char *array3[1000];
    int k = 0;
    while (p3 != NULL) {
        array3[k++] = p3;
        p3 = strtok(NULL, ":,");
    }

    int sum3 = 0;
    int count3 = 0;
    int piece3[15];
    for (k = 1; k < 16; ++k) {
        piece3[k] = atoi(array3[k]);
        sum3 += piece3[k];
        count3++;
    }
    printf("%s%d, %s%d \n", "Group C: count: ", count3, "sum: ", sum3);

    for (int i = 1; i < 16; ++i) {
        printf("%d\n", piece3[i]);
    }

    //---------------------------------------------------------------------------

    char *p4 = strtok(str_out[7], ":,");
    char *array4[1000];
    int m = 0;
    while (p4 != NULL) {
        array4[m++] = p4;
        p4 = strtok(NULL, ":,");
    }

    int sum4 = 0;
    int count4 = 0;
    int piece4[15];
    for (m = 1; m < 16; ++m) {
        piece4[m] = atoi(array4[m]);
        sum4 += piece4[m];
        count4++;
    }
    printf("%s%d, %s%d \n", "Group D: count: ", count4, "sum: ", sum4);

    for (int i = 1; i < 16; ++i) {
        printf("%d\n", piece4[i]);
    }
    //---------------------------------------------------------------------------



    // calculating median:
    qsort(str_out[1], 14, sizeof(int), cmpfunc);
    qsort(str_out[3], 12, sizeof(int), cmpfunc);
    qsort(str_out[5], 15, sizeof(int), cmpfunc);
    qsort(str_out[7], 15, sizeof(int), cmpfunc);



    //for (int i = 1; i < 15; ++i) {
    //   printf("%d ,", qsort(str_out[1]));
    //}


    //int n = (n + 1) / 2 - 1;

    return 0;
}