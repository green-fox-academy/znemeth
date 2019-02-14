//
// Created by NEMETH on 2019.02.14..
//

#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include "employee.h"

class Manager : public Employee
{
public:
    Manager(std::string name, int experience = 0);
    void work() override;
    void haveAMeeting();

protected:
    int _moodLevel = 400;
};

#endif //RESTAURANT_MANAGER_H
