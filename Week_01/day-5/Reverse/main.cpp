#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[5] = {3, 4, 5, 6, 7};
    int ak[5];

    ak[0] = aj [4];
    ak[1] = aj [3];
    ak[2] = aj [2];
    ak[3] = aj [1];
    ak[4] = aj [0];

    for (int i=0; i<5; i++){
       aj[i] = ak[i];
    }

    for (int i=0; i<5; i++){
        std::cout<< aj[i] <<std::endl;
    }

    return 0;
}