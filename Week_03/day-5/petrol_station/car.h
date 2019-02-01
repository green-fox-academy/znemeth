//
// Created by NEMETH on 2019.02.01..
//

#ifndef PETROL_STATION_CAR_H
#define PETROL_STATION_CAR_H


class Car {
    int gasAmount;
    int capacity;
public:
    Car(int gasAmount, int capacity);
    bool isfull();
    void fill();
    void setgasAmount(int gasAmount);
    int getgasAmount();
};


#endif //PETROL_STATION_CAR_H
