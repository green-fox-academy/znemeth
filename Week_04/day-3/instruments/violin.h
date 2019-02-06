//
// Created by NEMETH on 2019.02.06..
//

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H

#include "StringedInstrument.h"
#include "instrument.h"
#include <string>

class Violin : public StringedInstrument
{
public:
    Violin();

    Violin(int numberOfStrings);

    std::string sound();

};


#endif //INSTRUMENTS_VIOLIN_H
