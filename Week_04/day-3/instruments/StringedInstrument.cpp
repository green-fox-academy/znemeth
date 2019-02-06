//
// Created by NEMETH on 2019.02.06..
//

#include "StringedInstrument.h"
#include "instrument.h"
#include <string>
#include <iostream>

void StringedInstrument::play(){
    std::cout<< _name <<", a "<< numberOfStrings << "-stringed instrument that goes"<< sound() << std::endl;

}
