#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::ifstream myfile("../content.txt");
    std::string line;

    if (myfile.is_open())
    {
        std::getline (myfile, line);

        std::string from("bloody");
        unsigned int start_pos = line.find(from);
        line.replace(start_pos, from.length(), "");

        std::string from2("Cock");
        unsigned int start_pos2 = line.find(from2);
        line.replace(start_pos2, from2.length(), "");

        std::string from3("fuck");
        unsigned int start_pos3 = line.find(from3);
        line.replace(start_pos3, from3.length(), "");

        std::cout << line << '\n';
        myfile.close();
    }
    else std::cout << "Where is the file?!" <<std::endl;

    return 0;
}