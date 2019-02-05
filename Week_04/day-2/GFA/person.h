//
// Created by NEMETH on 2019.02.05..
//

#ifndef GFA_PERSON_H
#define GFA_PERSON_H
#include <string>

class Person {

public:
    Person();
    Person(std::string name, int age, std::string gender);
    virtual void introduce();

    virtual void getGoal();

protected:
    std::string _name;
    int _age;
    std::string _gender;
};


#endif //GFA_PERSON_H