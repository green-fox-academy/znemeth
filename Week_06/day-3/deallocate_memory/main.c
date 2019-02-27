#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free

int main()
{
    int *pointer = NULL;
    pointer = (int *) malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        pointer[i] = i * 2;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d \n", pointer[i]);
    }

    realloc(pointer, 0);

    /*
     According to documentation:
    "If new_size is zero, the behavior is implementation defined (null pointer may be returned (in which case the
     old memory block may or may not be freed), or some non-null pointer may be returned that may not be used to
     access storage)."
     */
    
    for (int i = 0; i < 10; i++) {
        printf("%d \n", pointer[i]);
    }

    return 0;
}