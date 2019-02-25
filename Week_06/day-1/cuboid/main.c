#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    int a;
    int b;
    int c;

    printf("1. side: \n");
    scanf("%d", &a);

    printf("2. side: \n");
    scanf("%d", &b);

    printf("3. side: \n");
    scanf("%d", &c);

    int area = 2 * (a * b + a * c + b * c);
    int vol = a * b * c;

    printf("Surface area: %d \n", area);
    printf("Volume: %d \n", vol);

    return 0;
}