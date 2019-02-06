#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "cohort.h"
#include "person.h"
#include "mentor.h"
#include "sponsor.h"


int main() {

    /*
    Person p("Lajos", 31, "male");
    p.introduce();
    p.getGoal();
    */
    std::vector<Person*> people;

    Person mark("Mark", 46, "male");
    people.push_back(&mark);
    Person jane;
    people.push_back(&jane);
    Student john("John Doe", 20, "male", "BME");
    people.push_back(&john);
    Student student;
    people.push_back(&student);
    Mentor gandhi("Gandhi", 148, "male", "senior");
    people.push_back(&gandhi);
    Mentor mentor;
    people.push_back(&mentor);
    Sponsor sponsor;
    people.push_back(&sponsor);
    Sponsor elon("Elon Musk", 46, "male", "SpaceX");
    people.push_back(&elon);

    student.skipDays(3);

    for (int i = 0; i < 5; i++) {
        elon.hire();
    }

    for (int i = 0; i < 3; i++) {
        sponsor.hire();
    }

    for(Person* person : people) {
        person->introduce();
        person->getGoal();
    }

    Cohort awesome = Cohort("AWESOME");
    awesome.addStudent(&student);
    awesome.addStudent(&john);
    awesome.addMentor(&mentor);
    awesome.addMentor(&gandhi);
    awesome.info();

    return 0;
}