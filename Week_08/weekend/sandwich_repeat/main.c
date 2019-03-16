#include <stdio.h>

/*
Create a sandwich struct
It should store:
- name
- price (float)
- weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
- a sandwich struct
- and an integer that represents how many sandwiches you want to order
*/

typedef struct sandwich
{
    char name[255];
    float price;
    float weight;
} sandwich_t;

float order_food(sandwich_t sz, int number)
{
    float total = sz.price * number;
    return total;
}

int main()
{
    int number;

    sandwich_t sz;
    number = 3;
    sz.price = 30;

    printf("Price of your order: %2.f\n", order_food(sz, number));
    return 0;
}