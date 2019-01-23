#include <iostream>
#include <fstream>
#include <string>

int flnm(std::string a){
    std::fstream myfile (a);
    std::string line;

    if (myfile.is_open())
    {
        int sorokszama = 0;
        while (getline (myfile,line)){
            sorokszama = sorokszama+1;
        }
        std::cout << sorokszama <<std::endl;
        myfile.close();
    }

    else std::cout << "0" <<std::endl;

}

int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    flnm ("my-file.txt");

    return 0;
}