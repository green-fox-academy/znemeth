#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

int adder (int x) {
    if (x < 1) {
        return 0;
    } else {
        return 2 + adder(x - 1);
    }
}

int main() {
      int bunny = 2;
      adder(bunny);
      std::cout << "Number: " << adder(bunny) << std::endl;
      return 0;
}