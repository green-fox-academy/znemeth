//
// Created by NEMETH on 2019.02.14..
//

#ifndef RESTAURANT_WAITER_H
#define RESTAURANT_WAITER_H

#include "employee.h"

class Waiter : public Employee
{
public:
    Waiter(std::string name, int experience = 0);
    void work() override;

protected:
    int _tips = 0;
};

#endif //RESTAURANT_WAITER_H
