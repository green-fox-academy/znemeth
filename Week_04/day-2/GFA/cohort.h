//
// Created by NEMETH on 2019.02.05..
//

#ifndef GFA_COHORT_H
#define GFA_COHORT_H
#include <string>
#include <vector>
#include "mentor.h"
#include "student.h"


class Cohort {
public:
    Cohort(std::string name);
    void info();
    void addStudent(Student*);
    void addMentor(Mentor*);
private:
    std::string _name;
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;
};


#endif //GFA_COHORT_H
