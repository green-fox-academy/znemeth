#include <iostream>
#include <fstream>
#include <map>

void parseData(std::string inputFileName, std::string outputFileName)
{
    std::ifstream inputFile;
    inputFile.open(inputFileName);

    if (!inputFile.is_open()) {
        throw "No input file!";
    }

    std::string name;
    std::string type;
    std::string date;

    std::map<std::string, int> usageData;

    while (inputFile >> name >> type >> date) {
        usageData[type]++;
        std::cout << "Name: " << name << ", Type: " << type << std::endl;
    }

    inputFile.close();

    std::ofstream outputFile;
    outputFile.open(outputFileName);

    outputFile << "Building usage" << std::endl << std::endl;

    for (std::map<std::string, int>::iterator it = usageData.begin(); it != usageData.end(); ++it) {
        outputFile << it->first << ": " << it->second << " " << std::endl;
    }
}

int main()
{
    try {
        parseData("../usage.txt", "../output.txt");

    } catch (std::string &e) {
        std::cout << "An exception occurred. " << e << std::endl;
    }

    return 0;
}