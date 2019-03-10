#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

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
    char manufacturer_name[255];
    float price;
    int year;
    enum transmission type;
} car_t;

int get_older_cars_than(struct car *array, int array_length, int age)
{
    int flag = 0;
    int year_now = 2019;
    for (int i = 0; i < array_length; i++) {
        int car_age = year_now - array[i].year;
        if (car_age > age) {
            flag++;
        }
    }
    return flag;
}

int get_transmission_count(struct car *array, int array_length, enum transmission trnsm)
{
    int flag = 0;
    for (int i = 0; i < array_length; i++) {
        if (array[i].type == trnsm) {
            flag++;
        }
    }
    return flag;
}

int main()
{
    car_t cars[3];

    cars[0].year = 1988;
    cars[1].year = 1989;
    cars[2].year = 1990;
    int cars_length = sizeof(cars) / sizeof(*cars);

    cars[0].type = MANUAL;
    cars[1].type = DUAL_CLUTCH;
    cars[2].type = SEMI_AUTOMATIC;

    printf("Number of cars (age): %d \n", get_older_cars_than(cars, cars_length, 29));
    printf("Number of cars (transmission type): %d \n", get_transmission_count(cars, cars_length, SEMI_AUTOMATIC));

    return 0;
}