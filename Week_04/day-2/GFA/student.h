//
// Created by NEMETH on 2019.02.05..
//

#ifndef GFA_STUDENT_H
#define GFA_STUDENT_H


#include "person.h"
#include <string>


class Student : public Person {
public:
    Student();
    Student(std::string name, int age, std::string gender, std::string previousOrganization, int skippedDays);

    void getGoal() override;
    void introduce() override;
    int skippedDays(int skippedDays, int numberOfDays);

protected:
    int _skippedDays;
    std::string _previousOrganization;

};


#endif //GFA_STUDENT_H
