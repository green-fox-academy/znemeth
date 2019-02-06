//
// Created by NEMETH on 2019.02.05..
//

#include <iostream>
#include "sponsor.h"

Sponsor::Sponsor() {
    _name = "Jane Doe";
    _age = 30;
    _gender = "female";
    _company = "Google";
    _hiredStudents = 0;
};

Sponsor::Sponsor(std::string name, int age, std::string gender, std::string company) {
    _name = name;
    _age = age;
    _gender = gender;
    _company = company;
    _hiredStudents = 0;
};

void Sponsor::introduce() {
    std::cout << "Hi, I'm" << _name << ", a " << _age << "year old " << _gender << " who represents" << _company << " and hired" << _hiredStudents << "students so far." << std::endl;
};

void Sponsor::getGoal() {
    std::cout << "My goal is: Hire brilliant junior software developers."<< std::endl;
};

void Sponsor::hire(){
    _hiredStudents++;
};