#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct
{
    char *address;
    int price;
    int rooms;
    int area;
} house_t;

house_t create_house(char *_address, int _price, int _rooms, int _area)
{
    house_t house;
    house.address = _address;
    house.price = _price;
    house.rooms = _rooms;
    house.area = _area;
    return house;
}

void pricing(house_t *house)
{
    if ((house->price / house->area) > 400) {
        printf("%s", "Do not buy it, it is way more expensive than the neighborhood!\n");
    } else {
        printf("%s", "Buy it! It is cheap!!!\n");
    }
}

int worth_to_buy(house_t array[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (pricing(&array[i])) {
            count++;
        }
    }
    return count;
}

int main()
{
    house_t house1 = create_house("Via Roma 41", 40000, 3, 100);
    house_t house2 = create_house("Via Gattamelata 14", 400000, 6, 130);
    house_t house3 = create_house("Via Donizetti 4", 1000, 1, 50);
    house_t house4 = create_house("Viale Gatti 167", 13450, 2, 300);
    house_t house5 = create_house("Via Milano 18", 60000, 4, 56);

    house_t array_of_houses[5];
    array_of_houses[0] = house1;
    array_of_houses[1] = house2;
    array_of_houses[2] = house3;
    array_of_houses[3] = house4;
    array_of_houses[4] = house5;

    int length = sizeof(array_of_houses) / sizeof(array_of_houses[0]);
    printf("Number of houses: %d \n", length);

    pricing(&house1);
    pricing(&house2);
    pricing(&house3);
    pricing(&house4);
    pricing(&house5);

    printf("That many houses worth to buy: %d\n", worth_to_buy(array_of_houses, length));

    return 0;
}