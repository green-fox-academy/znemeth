#include <iostream>
#include "Aircraft.h"

int main()
{
    Aircraft wizz(F16);
    Aircraft ryan(F35);
    std::cout << "Aircraft type: " << aircraftToString(wizz.get_aircraftType()) << std::endl;
    std::cout << "Aircraft type: " << aircraftToString(ryan.get_aircraftType()) << std::endl;

    std::cout << "Remaining ammo after filling: " << wizz.refill(20) << " and ammo in aircraft: " << wizz.get_ammoStore() << std::endl;
    std::cout << "Remaining ammo after filling: " << ryan.refill(30) << " and ammo in aircraft: " << ryan.get_ammoStore() << std::endl;

    return 0;
}