//
// Created by NEMETH on 2019.02.01..
//

#include "station.h"


station::station(){
    gasAmount = 100;
}

void station::fill(Car& car){ /*első típus, második a név */
    while (!car.isfull()){
        // car.setgasAmount(car.getgasAmount()+1);
        car.fill();
        gasAmount--;
    }
}

int station::getgasAmount(){
    return gasAmount;
}