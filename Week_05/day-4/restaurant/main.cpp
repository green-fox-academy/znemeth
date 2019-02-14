#include <iostream>
#include "restaurant.h"
#include "waiter.h"
#include "chef.h"
#include "manager.h"

int main()
{

    Restaurant restaurant ("Ristorante Don Marco", 1222);
    Waiter waiter1("Carlo", 100);
    Chef chef1("Uccio");
    Manager manager1("Fabrizio");


    restaurant.hire(waiter1);
    restaurant.guestArrived();

    chef1.work();
    manager1.haveAMeeting();
    manager1.work();
    waiter1.work();
    chef1.cook("pizza prosciutto");

    std::cout << "" << std::endl;
    return 0;
}