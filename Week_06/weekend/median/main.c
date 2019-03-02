#include <stdio.h>
#include <malloc.h>
#include <mem.h>

// Every line contains the name of the group and after a colon, the height of people in the group separated by commas
// Find the group where the median is the lowest.
// Note that the groups do not necessarily contain the same amount of people

int min_of_four(int a, int b, int c, int d)
{
    if (a < b && a < c && a < d) {
        return a;
    } else if (b < a && b < c && b < d) {
        return b;
    } else if (c < a && c < b && c < d) {
        return c;
    } else return d;
}

void swap(int *p, int *q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;
}

void sort(int a[], int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
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
    int sortarray1[14];
    for (i = 1; i < 15; ++i) {
        piece1[i] = atoi(array1[i]);
        sum1 += piece1[i];
        sortarray1[i - 1] = piece1[i];
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
    int sortarray2[12];
    for (j = 1; j < 13; ++j) {
        piece2[j] = atoi(array2[j]);
        sum2 += piece2[j];
        sortarray2[j - 1] = piece2[j];
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
    int sortarray3[15];
    for (k = 1; k < 16; ++k) {
        piece3[k] = atoi(array3[k]);
        sum3 += piece3[k];
        sortarray3[k - 1] = piece3[k];
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
    int sortarray4[15];
    for (m = 1; m < 16; ++m) {
        piece4[m] = atoi(array4[m]);
        sum4 += piece4[m];
        sortarray4[m - 1] = piece4[m];
        count4++;
    }
    printf("%s%d, %s%d \n", "Group D: count: ", count4, "sum: ", sum4);

    for (int i = 1; i < 16; ++i) {
        printf("%d\n", piece4[i]);
    }

    //---------------------------------------------------------------------------

    // calculating median:

    int n = 14;
    sort(sortarray1, n);
    n = (n + 1) / 2 - 1;
    printf("Median in Group A: %d \n", sortarray1[n]);

    int p = 12;
    sort(sortarray2, p);
    p = (p + 1) / 2 - 1;
    printf("Median in Group B: %d \n", sortarray2[p]);

    int q = 15;
    sort(sortarray3, q);
    q = (q + 1) / 2 - 1;
    printf("Median in Group C: %d \n", sortarray3[q]);

    int r = 15;
    sort(sortarray4, r);
    r = (r + 1) / 2 - 1;
    printf("Median in Group D: %d \n", sortarray4[r]);

    printf("The median is %d cm in Group D.", min_of_four(sortarray1[n], sortarray2[p], sortarray3[q], sortarray4[r]));

    return 0;
}