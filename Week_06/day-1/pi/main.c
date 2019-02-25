#include <stdio.h>
#include <stdlib.h>

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

#define PI 3.14

float calc(rad)
{
    float area = rad * rad * PI;
    return area;
}

int main()
{
    int rad;
    printf("Let the radius be: \n");
    scanf("%d", &rad);

    calc(rad);

    printf("Area: %.2f \n", calc(rad));
    return 0;
}