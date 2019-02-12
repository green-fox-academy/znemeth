//
// Created by NEMETH on 2019.02.12..
//

#ifndef PETROL_STATION_AGAIN_CAR_H
#define PETROL_STATION_AGAIN_CAR_H

class Car
{
public:
    Car();
    Car(int gasAmount, int capacity);
    bool isFull();
    void fill();
    void setgasAmount(int gasAmount);
    int getgasAmount();

protected:
    int _gasAmount;
    int _capacity;
};

#endif //PETROL_STATION_AGAIN_CAR_H
