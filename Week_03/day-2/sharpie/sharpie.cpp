//
// Created by NEMETH on 2019.01.29..
//
#include <iostream>
#include "sharpie.h"

Sharpie::Sharpie(std::string colorIN, float widthIN) {
    color = colorIN;
    width = widthIN;
    inkAmount = 100;
}

    void Sharpie::use()
    {
        inkAmount--;
    }
