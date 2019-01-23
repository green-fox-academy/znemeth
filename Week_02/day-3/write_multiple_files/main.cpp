#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number parameter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

int fuggveny (std::string na, std::string w, int n){

    std::ofstream myfile;
    std::string path = "C:\\Users\\NEMETH\\Desktop\\greenfox\\znemeth\\Week_02\\day-3\\write_multiple_files\\";
    myfile.open(path + na);

    for (int i=0; i<n; i++) {
       myfile << w <<  '\n';
    }
}


int main() {

    std::string name;
    std::string word;
    int number;

    std::cout<< "What should be the filename? (e.g. xyz.txt)" << std::endl;
    std::cin>> name;
    std::cout<< "Write a word!" << std::endl;
    std::cin>> word;
    std::cout<< "Write a number!" << std::endl;
    std::cin>> number;

    fuggveny(name, word, number);



    return 0;
}