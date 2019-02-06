//
// Created by NEMETH on 2019.02.05..
//

#ifndef GFA_SPONSOR_H
#define GFA_SPONSOR_H
#include <string>
#include "person.h"

class Sponsor : public Person {
public:
    Sponsor();
    Sponsor(std::string name, int age, std::string gender, std::string company);

    void getGoal() override;
    void introduce() override;
    int hiredStudents();
    void hire();

protected:
    int _hiredStudents;
    std::string _company;
};


#endif //GFA_SPONSOR_H
