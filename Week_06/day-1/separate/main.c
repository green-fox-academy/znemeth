#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int rad;
    printf("Let the radius be: \n");
    scanf("%d", &rad);

    printf("Area: %.2f \n", AREA);
    printf("Circumference: %.2f \n", CIRCUMFERENCE);
    return 0;
}