//
// Created by NEMETH on 2019.02.14..
//

#ifndef RESTAURANT_RESTAURANT_H
#define RESTAURANT_RESTAURANT_H

#include <string>
#include <vector>
#include "employee.h"

class Restaurant
{
public:
    Restaurant(std::string name, int founded);
    void guestArrived();
    void hire(Employee &employee);

protected:
    std::string _name;
    int _founded;
    std::vector<Employee*> _employees;

};

#endif //RESTAURANT_RESTAURANT_H
