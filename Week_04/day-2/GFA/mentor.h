//
// Created by NEMETH on 2019.02.05..
//

#ifndef GFA_MENTOR_H
#define GFA_MENTOR_H


#include "person.h"

class Mentor : public Person {
    public:
        Mentor();
        Mentor(std::string name, int age, std::string gender, std::string level);

        void getGoal() override;
        void introduce() override;

    protected:

        std::string _level;
};


#endif //GFA_MENTOR_H
