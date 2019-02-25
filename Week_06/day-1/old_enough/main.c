#include <stdio.h>
#include <stdlib.h>

int etoh(age)
{
    if (age < 19) {
        printf("No alcohol, Babe! \n");
    } else if (age > 18) {
        printf("Go ahead, buy EtOH! \n");
    }
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;
    printf("Your age: \n");
    scanf("%d", &age);

    etoh(age);

    return 0;
}