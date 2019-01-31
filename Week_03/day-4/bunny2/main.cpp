#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).

int adder (int x) {
 //   if (x < 1) {
  //      return 0;
 //   }
   // if (x % 2 == 0) {

    if (x < 1) {
        return 0;
    } else if (x % 2 == 1) {
        return 2 + adder(x - 1);
    } else if (x % 2 == 0) {
        return 3 + adder(x - 1);
    }
}

int main() {
    int bunny = 5;
    adder(bunny);
    std::cout << "Number of ears: " << adder(bunny) << std::endl;
    return 0;
}