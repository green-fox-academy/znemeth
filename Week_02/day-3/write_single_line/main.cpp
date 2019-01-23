#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream myfile;
    myfile.open("mytext.txt");
    myfile << "Dr. Zoltan Adam Nemeth" << '\n';
    myfile.close();

    return 0;
}