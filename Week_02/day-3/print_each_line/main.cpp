#include <iostream>
#include <fstream>
#include <string>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory


    std::ifstream myfile ("my-file.txt");
    std::string line;

    if (myfile.is_open())
    {
        while (getline (myfile,line)){
            std::cout << line << '\n';
        }
        myfile.close();
    }

    else std::cout << "Where is the file?!" <<std::endl;

    return 0;
}