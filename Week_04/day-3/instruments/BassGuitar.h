//
// Created by NEMETH on 2019.02.06..
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H

#include <string>
#include "StringedInstrument.h"
#include "instrument.h"

class BassGuitar : public StringedInstrument {
public:
    BassGuitar();

    BassGuitar(int numberOfStrings);

    std::string sound();

};


#endif //INSTRUMENTS_BASSGUITAR_H
