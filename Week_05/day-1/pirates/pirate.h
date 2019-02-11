//
// Created by NEMETH on 2019.02.11..
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <string>

class Pirate
{
public:
    Pirate(std::string name, bool isCaptain, bool hasWoodenleg);

    void work();
    void party();
    std::string toString();
    bool isCaptain();
    bool hasWoodenleg();
    int getGold();
    std::string getName();

private:
    std::string _name;
    int _gold;
    int _healthPoints;
    bool _isCaptain;
    bool _hasWoodenleg;
};

#endif //PIRATES_PIRATE_H
