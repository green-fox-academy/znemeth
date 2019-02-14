#include <iostream>
#include "restaurant.h"
#include "waiter.h"
#include "chef.h"
#include "manager.h"

int main()
{

    Restaurant restaurant("Ristorante Don Marco", 1822);
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

    std::cout << "Restaurant name: " << restaurant.get_name() << std::endl;
    std::cout << "Restaurant established: " << restaurant.get_founded() << std::endl;

    std::cout << "Manager name: " << manager1.get_name() << std::endl;
    std::cout << "Manager experience: " << manager1.get_experience() << std::endl;
    std::cout << "Manager mood level: " << manager1.get_moodLevel() << std::endl;

    std::cout << "Waiter name: " << waiter1.get_name() << std::endl;
    std::cout << "Waiter experience: " << waiter1.get_experience() << std::endl;
    std::cout << "Waiter tips: " << waiter1.get_tips() << std::endl;

    std::cout << "Chef name: " << chef1.get_name()<< std::endl;
    std::cout << "Chef experience: " << chef1.get_experience()<< std::endl;

    /*
    std::cout << "" << << std::endl;
    std::cout << "" << << std::endl;
    std::cout << "" << << std::endl;
    std::cout << "" << << std::endl;
    std::cout << "" << << std::endl;
    std::cout << "" << << std::endl;
    */

    return 0;
}