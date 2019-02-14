#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int main()
{
    std::ifstream inputFile;
    std::string fileName("../lyrics.txt");
    inputFile.open(fileName);

    try {
        if (!inputFile.is_open())
            throw "No such file!";
    } catch (char const *e) {
        std::cout << "An error occurred: " << e << std::endl;
    }

    std::string line;
    int cnt = 0;
    while (std::getline(inputFile, line)) {
        std::stringstream stringStream(line);
        cnt++;
    }

    inputFile.close();

    std::cout << cnt << std::endl;
}