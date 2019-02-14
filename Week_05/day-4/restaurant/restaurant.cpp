//
// Created by NEMETH on 2019.02.14..
//

#include "restaurant.h"
#include "employee.h"

Restaurant::Restaurant(std::string name, int founded)
{
    _name = name;
    _founded = founded;
}

void Restaurant::guestArrived()
{
    for (int i = 0; i < _employees.size(); ++i) {
        _employees[i]->work();
    }
}

void Restaurant::hire(Employee &employee)
{
    _employees.push_back(&employee);
}
