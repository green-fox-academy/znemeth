#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    std::string animals[3] = {"koal", "pand", "zebr"};


    //std::cout<< animals[0]<<"a" <<std::endl;
    //std::cout<< animals[1]<<"a" <<std::endl;
    //std::cout<< animals[2]<<"a" <<std::endl;

    for (int i=0; i<3; i++){
        std::cout<< animals[i]<<"a" <<std::endl;
    };


    return 0;
}