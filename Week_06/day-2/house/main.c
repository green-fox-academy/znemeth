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
        printf("%s", "Do not buy it, it is way more expensive than the neighborhood!");
    } else {
        printf("%s", "Buy it! It is cheap!!!");
    }
}

int main()
{
    house_t house1 = create_house("Via Roma 41", 40000, 3, 100);
    pricing(&house1);

    return 0;
}