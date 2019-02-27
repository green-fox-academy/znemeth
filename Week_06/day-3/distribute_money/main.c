#include <stdio.h>
#include <stdlib.h>

// The rich uncle has just died and you need to distribute his heritage among the relatives. The money you have to distribute is $1024
// Generate a random number between 20 and 50. This number will be the amount of relatives that showed up at the inheritance party.
// Allocate an array for them. Each element of the array will represent a relative.
// You need to generate a random number between 0 and the number of relatives to decide which one is the winner.
// The winner always gets the half of the remaining money. You need to generate random numbers until all the money is gone.
// Print the amount of money each relative got on the party. Print 0 for the unlucky ones.

//For example: 0,0,0,0,128,4,0,0,2,0,512,0,0,0,0,0,0,32,0,64,0,0,1,8,0,0,16,256

int main()
{
    int money = 1024;
    int lower = 20;
    int upper = 50;

    int number_relatives = lower + (rand() % (upper - lower + 1));

    printf("Number of relatives: %d \n", number_relatives);

    int *relatives = (int *) calloc(number_relatives, sizeof(int *));

    while (money != 0) {
        int order_lucky_relatives = (rand() % (number_relatives));
        relatives[order_lucky_relatives] += money / 2;
        money /= 2;
    }

    for (int i = 0; i < number_relatives; i++) {
        printf("%d ", relatives[i]);
    }

    int sum = 0;
    for (int i = 0; i < number_relatives; i++) {
        sum += relatives[i];
    }

    printf("\nTotal money: %d ", sum);

    free(relatives);
    return 0;
}