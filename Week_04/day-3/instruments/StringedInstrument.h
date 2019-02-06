//
// Created by NEMETH on 2019.02.06..
//

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H

#include <string>
#include "instrument.h"

class StringedInstrument : public Instrument {

public:
    virtual std::string sound() = 0;

    void play();

protected:
    int _numberOfStrings;
};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
