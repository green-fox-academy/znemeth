//
// Created by NEMETH on 2019.02.06..
//

#include "violin.h"
#include "StringedInstrument.h"
#include "instrument.h"

Violin::Violin() {
    _numberOfStrings = 4;
    _name = "Violin";
}

Violin::Violin(int numberOfStrings) {
    _numberOfStrings = numberOfStrings;
    _name = "Violin";
}

std::string Violin::sound() {
    return "Screech";
}
