#include <stdio.h>

typedef struct
{
    char *address;
    int price;
    int room;
    int area;
} house_t;

house_t create_house(char *_address, int _price, int _room, int _area)
{
    house_t house;
    house.address = _address;
    house.price = _price;
    house.room = _room;
    house.area = _area;
    return house;
}

int pricing(house_t *house)
{
    if ((house->price / house->area) > 400) {
        return 0;
    } else {
        return 1;
    }
}

int worth_to_buy(house_t array[], int length)
{
    int count = 0;
    for (int i = 0; i < length; ++i) {
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
    house_t house3 = create_house("Via Donizetti 4", 100, 1, 50);

    house_t array[3];
    array[0] = house1;
    array[1] = house2;
    array[2] = house3;

    int length = sizeof(array) / sizeof(*array);
    printf("Number of houses: %d \n", length);

    pricing(&house1);
    pricing(&house2);
    pricing(&house3);

    printf("Number of houses that worth to buy: %d\n", worth_to_buy(array, length));


    return 0;
}