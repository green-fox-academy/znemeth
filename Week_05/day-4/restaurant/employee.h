//
// Created by NEMETH on 2019.02.14..
//

#ifndef RESTAURANT_EMPLOYEE_H
#define RESTAURANT_EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee(std::string name, int experience = 0);

    virtual void work() = 0;

protected:
    std::string _name;
public:
    const std::string &get_name() const;

    int get_experience() const;

protected:
    int _experience = 0;
};

#endif //RESTAURANT_EMPLOYEE_H
