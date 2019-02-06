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
    Student(std::string name, int age, std::string gender, std::string previousOrganization);

    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);

protected:
    int _skippedDays = 0;
    std::string _previousOrganization;

};


#endif //GFA_STUDENT_H
