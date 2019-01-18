#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    //int a;
    int numList[] = {3, 4, 5, 6, 7};

    std::cout << numList [0] *2<<std::endl;
    std::cout << numList [1] *2<<std::endl;
    std::cout << numList [2] *2<<std::endl;
    std::cout << numList [3] *2<<std::endl;
    std::cout << numList [4] *2<<std::endl;

    return 0;
}