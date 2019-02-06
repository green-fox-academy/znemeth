//
// Created by NEMETH on 2019.02.06..
//

#include "BassGuitar.h"
#include "StringedInstrument.h"
#include "instrument.h"


BassGuitar::BassGuitar() {
    _numberOfStrings = 4;
    _name = "Bassguitar";
}

BassGuitar::BassGuitar(int numberOfStrings) {
    _numberOfStrings = numberOfStrings;
    _name = "Bassguitar";
}

std::string BassGuitar::sound() {
    return "Duum-duum-duum";
}