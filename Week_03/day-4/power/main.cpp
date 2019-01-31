#include <iostream>
#include "math.h"

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

int powercalc (int x, int y) {
    if (y < 1) {
        return 0;
    } else {
        return pow(x, y);
    }
}

int main() {
   int num = 3;
   int power = 3;
   powercalc(num, power);
   std::cout << "Number: " << powercalc(num, power) << std::endl;
   return 0;
}
