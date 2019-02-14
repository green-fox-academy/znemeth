//
// Created by NEMETH on 2019.02.14..
//

#include "chef.h"

void Chef::work()
{
    _experience++;
}

void Chef::cook(std::string foodName)
{
    _meals[foodName]++;
}

Chef::Chef(std::string name, int experience) : Employee(name, experience)
{

}
