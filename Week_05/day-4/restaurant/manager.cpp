//
// Created by NEMETH on 2019.02.14..
//

#include "manager.h"

void Manager::work()
{
    _experience++;
    void haveAMeeting();
}

void Manager::haveAMeeting()
{
    _moodLevel -= _experience;
}

Manager::Manager(std::string name, int experience) : Employee(name, experience)
{

}

int Manager::get_moodLevel() const
{
    return _moodLevel;
}
