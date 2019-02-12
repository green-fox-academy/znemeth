#include <iostream>
#include "pirate.h"
#include "ship.h"

int main()
{
    Pirate pirate1("Jack", true, true);         /*name, captain, woodenleg*/
    Pirate pirate2("Holloway", false, false);
    Pirate pirate3("Peter", false, true);

    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;
    std::cout << pirate3.toString() << std::endl;

    Ship ship;
    ship.addPirate(pirate1);
    ship.addPirate(pirate2);
    ship.addPirate(pirate3);

    std::cout << "The total amount of gold on the ship is " << ship.getGolds() << std::endl;
    std::cout << " " << std::endl;

    ship.prepareForBattle();
    ship.lastDayOnTheShip();

    pirate1.work();
    pirate2.work();
    pirate3.work();

    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;
    std::cout << pirate3.toString() << std::endl;

    std::cout << "The total amount of gold on the ship is " << ship.getGolds() << std::endl;
    return 0;
}