#include <stdio.h>

int main()
{
    int i = 14;
    int j = i << 1;
    printf("%d \n\n", j);

    int k = i >> 1;
    printf("%d \n\n", k);

    for (int m = 0; m < 5; ++m) {
        i = i << 1;
        printf("%d\n", i);
    }

    // bitwise OR
    int a = 6; // bin: 110
    int b = 2; // bin: 010
    int c = a | b; //result: 110 that is 6 in dec
    printf("%d\n", c);

    // bitwise XOR
    int d = 6; // bin: 110
    int e = 2; // bin: 010
    int f = d ^ e; //result: 100 that is 4 in dec
    printf("%d\n", f);

    return 0;
}