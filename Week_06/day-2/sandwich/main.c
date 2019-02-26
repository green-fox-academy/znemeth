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
    char name[10];
    float price;
    float weight;
} szendvics;

float price(szendvics sz, int num)
{
    //float(num);
    float total = sz.price * num;
    return total;
}

int main()
{
    int num;

    szendvics sz;
    sz.price = 50;
    num = 2;

    price(sz, num);

    printf("Your order %2.f$, that contains %d sandwich(es),\n", price(sz, num), num);
    return 0;
}