#include <stdio.h>
#include "string.h"

enum transmission
{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
};

typedef struct car
{
    char name_manufacturer[255];
    float price;
    int year;
    enum transmission type;
} car_t;

int main()
{
    car_t cars[3];

    //cars[0].name_manufacturer = "FIAT";
    cars[0].price = 100000;
    cars[0].year = 1988;
    cars[0].type = MANUAL;

    cars[1].year = 1990;
    cars[1].type = SEMI_AUTOMATIC;

    cars[2].year = 2000;
    cars[2].type = MANUAL;

    int number_car = sizeof(cars) / sizeof(*cars);

    printf("Number (transmission): %d \n", get_transmission_count(cars, number_car, MANUAL));
    printf("Number (age): %d \n", get_cars_older_than(cars, number_car, 29));

    return 0;
}

int get_cars_older_than(struct car *array, int array_length, int age)
{
    int flag = 0;
    int year_now = 2019;

    for (int i = 0; i < array_length; ++i) {
        int car_age = year_now - array[i].year;
        if (car_age > age) {
            flag++;
        }
    }
    return flag;
};

int get_transmission_count(struct car *array, int array_length, enum transmission trnsm)
{
    int flag = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].type == trnsm) {
            flag++;
        }
    }
    return flag;
};