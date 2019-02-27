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

void reverseArray(int arr[], int start, int end)
{
    int temp;
    if (start >= end)
        return;
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int size)
{
    printf("The descending array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int *pointer1 = NULL;
    int *pointer2 = NULL;

    pointer1 = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        pointer1[i] = i * 2;
    }

    printf("1. array: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", pointer1[i]);
    }
    printf("\n");

    pointer2 = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        pointer2[i] = i * 2 + 1;
    }

    printf("2. array: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", pointer2[i]);
    }
    printf("\n");

    int *pointer3 = NULL;
    pointer3 = (int *) malloc(20 * sizeof(int));
    for (int i = 0; i < 20; i++) {
        if (i > 9) {
            pointer3[i] = (pointer2[i - 10]);
        } else {
            pointer3[i] = pointer1[i];
        }
    }

    printf("Merged array: \n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", pointer3[i]);
    }
    printf("\n");

    qsort(pointer3, 20, sizeof(int), cmpfunc);

    reverseArray(pointer3, 0, 19);
    printArray(pointer3, 20);

    free(pointer1);
    free(pointer2);
    free(pointer3);
    return 0;
}