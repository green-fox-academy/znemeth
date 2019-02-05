//
// Created by NEMETH on 2019.02.05..
//

#include <iostream>
#include "student.h"

Student::Student() {
    _name = "Jane Doe";
    _age = 30;
    _gender = "female";
    _previousOrganization = "The School of Life";
    _skippedDays = 0;
};

Student::Student(std::string name, int age, std::string gender, std::string previousOrganization, int skippedDays) {
    _name = name;
    _age = age;
    _gender = gender;
    _previousOrganization = previousOrganization;
    _skippedDays = skippedDays;
};

void Student::introduce() {
    std::cout << "Hi, I'm" << _name << ", a " << _age << "year old " << _gender << "and " << _previousOrganization
              << "." << std::endl;
};

void Student::getGoal() {
    std::cout << "My goal is: Live for the moment!" << std::endl;
};

void skippedDays(int skippedDays, int numberOfDays) {
    skippedDays += numberOfDays;
};