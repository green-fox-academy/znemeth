#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *args[]) {

    std::vector<std::string> words = {"fuck", "bloody", "cock", "shit", "fucker", "fuckstick", "asshole", "dick", "piss" };

    std::ifstream myfile("../content.txt");
    std::string line;

    std::getline (myfile, line);
    //std::cout << line;


    for (int i = 0; i < line.size(); ++i) {
        if (line[i]  == 0) {
            line.erase(line.begin() + i);
                // !!! We need to decrement the loop variable, otherwise
                // it points to the next element after the deletion !!!
            --i;
        }
    }

}