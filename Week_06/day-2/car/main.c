#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type
{
    VOLVO, TOYOTA, LAND_ROVER, TESLA
};

struct car
{
    enum car_type type;
    double km;
    double gas;
};

void carInfo(struct car kocsi)
{
    if (kocsi.type == VOLVO) {
        printf("Yor car is a Volvo with %.0f km and %.2f L gas. \n", kocsi.km, kocsi.gas);
    } else if (kocsi.type == TOYOTA) {
        printf("Yor car is a Toyota with %.0f km and %.2f L gas. \n", kocsi.km, kocsi.gas);
    } else if (kocsi.type == LAND_ROVER) {
        printf("Yor car is a Land Rover with %.0f km and %.2f L gas. \n", kocsi.km, kocsi.gas);
    } else if (kocsi.type == TESLA) {
        printf("Yor car is a Tesla with %.0f km. \n", kocsi.km);
    }
}

int main()
{
    struct car kocsi1;
    kocsi1.type = VOLVO;
    kocsi1.km = 1544;
    kocsi1.gas = 45;

    struct car kocsi2;
    kocsi2.type = TESLA;
    kocsi2.km = 150;
    kocsi2.gas = 11;

    carInfo(kocsi1);
    carInfo(kocsi2);

    return 0;
}