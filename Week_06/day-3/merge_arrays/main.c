#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int cmpfunc(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int main()
{
    int *pointer1 = NULL;
    int *pointer2 = NULL;

    pointer1 = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        pointer1[i] = i * 2;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d", pointer1[i]);
    }

    pointer2 = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        pointer2[i] = i * 2 + 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d \n", pointer2[i]);
    }

    int *pointer3 = NULL;
    pointer3 = (int *) malloc(20 * sizeof(int));
    for (int i = 0; i < 20; i++) {
        if (i > 9) {
            pointer3[i] = (pointer2[i - 10]);
        } else {
            pointer3[i] = pointer1[i];
        }
    }

    for (int i = 0; i < 20; i++) {
        printf("%d \n", pointer3[i]);
    }

    qsort(pointer3, 20, sizeof(int), cmpfunc);

    for (int i = 0; i < 20; i++) {
        printf("%d ", pointer3[i]);
    }

    free(pointer1);
    free(pointer2);
    free(pointer3);
    return 0;
}