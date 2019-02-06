//
// Created by NEMETH on 2019.02.06..
//

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H

#include "instrument.h"
#include "StringedInstrument.h"
#include <string>

class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar();

    ElectricGuitar(int numberOfStrings);

    std::string sound();

};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
