//
// Created by NEMETH on 2019.02.05..
//

#include <iostream>
#include "person.h"

Person::Person() {
    _name = "Jane Doe";
    _age = 30;
    _gender = "female";
};

Person::Person(std::string name, int age, std::string gender) {
    _name = name;
    _age = age;
    _gender = gender;
};

void Person::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << _gender << "." << std::endl;
};

void Person::getGoal() {
    std::cout << "My goal is: Live for the moment!" << std::endl;
};
