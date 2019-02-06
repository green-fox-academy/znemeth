//
// Created by NEMETH on 2019.02.06..
//

#include "ElectricGuitar.h"
#include "StringedInstrument.h"
#include "instrument.h"

ElectricGuitar::ElectricGuitar() {
    _numberOfStrings = 6;
    _name = "ElectricGuitar";
}

ElectricGuitar::ElectricGuitar(int numberOfStrings) {
    _numberOfStrings = numberOfStrings;
    _name = "ElectricGuitar";
}

std::string ElectricGuitar::sound() {
    return "Twang";
}