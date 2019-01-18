#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int a = 24;
    int out = 0;
    // if a is even increment out by one
    if (a % 2 == 1) {
        a = a + 1;
    };

    //std::cout << out << std::endl;


    int b = 13;
    std::string out2;
    // if b is between 10 and 20 set out2 to "Sweet!"
    if (b > 10 && b < 20) {
        std::cout << "Sweet!" << std::endl;
    };
    // if less than 10 set out2 to "Less!",
    if (10 > b) {
        std::cout << "Less!" << std::endl;
    };
    // if more than 20 set out2 to "More!"
    if (b > 20) {
        std::cout << "More!" << std::endl;
    };

    std::cout << out2 << std::endl;


    int c = 123;
    int credits = 100;
    bool isBonus = false;
    // if credits are at least 50,
    // and isBonus is false decrement c by 2
    if (credits < 51 && isBonus == false) {
        c = c - 2;
    };

    // if credits are smaller than 50,
    // and isBonus is false decrement c by 1
    if (credits < 50 && isBonus == false) {
        c = c - 1;
    };


    // if isBonus is true c should remain the same
    if (isBonus == true) {
        c = c;
    };


    std::cout << c << std::endl;


    int d = 8;
    int time = 120;
    std::string out3;
    // if d is dividable by 4
    // and time is not more than 200
    // set out3 to "check"
    if (d % 4 == 0 && time < 201) {
        std::cout << "check" << std::endl;

        if (time > 200) {
            std::cout << "Time out!" << std::endl;
        } else {
            std::cout << "Run Forest Run!" << std::endl;
        }
    }




    // if time is more than 200
    // set out3 to "Time out"


    // otherwise set out3 to "Run Forest Run!"



    std::cout << out3 << std::endl;

    return 0;
}