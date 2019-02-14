//
// Created by NEMETH on 2019.02.14..
//

#ifndef RESTAURANT_CHEF_H
#define RESTAURANT_CHEF_H

#include <string>
#include <vector>
#include <map>
#include "employee.h"

class Chef : public Employee
{
public:
    Chef(std::string name, int experience = 0);
    void work() override;
    void cook(std::string foodName);

protected:
    std::map<std::string, int> _meals;
};

#endif //RESTAURANT_CHEF_H
