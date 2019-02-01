//
// Created by NEMETH on 2019.01.29..
//

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie {
public:
    Sharpie (std::string colorIN, float widthIN);
    void use ();
    std::string getColor();
    float getWidth();
    float getInkAmount();

private:
    std::string color;
    float width;
    float inkAmount;
};


#endif //SHARPIE_SHARPIE_H
