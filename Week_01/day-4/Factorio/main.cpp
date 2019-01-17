#include <iostream>
#include <string>

int fact(int a, int b){

    int s = 1;
    for (int i = 1; i <= a; i+=1){
        s = s * i;
    }
    //s = b;    w/ comment it writes the factorial out!!!
    s = b;
    return s;
}

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int x; int y;
    std::cout << "Write a number for fact: " << std::endl;
    std::cin>> x;

    std::cout << "Write a number for overwrite: " << std::endl;
    std::cin>> y;


    fact(x, y);
    std::cout << "The number: " << fact(x,y) << std::endl;

    return 0;
}