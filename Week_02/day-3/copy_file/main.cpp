#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

int kopi (std::string fi1, std::string fi2) {

    std::ifstream myfile1;
    std::string path1 = "C:\\Users\\NEMETH\\Desktop\\greenfox\\znemeth\\Week_02\\day-3\\copy_file\\";
    myfile1.open(path1 + fi1);
    std::string line;


    std::ofstream myfile2;
    std::string path2 = "C:\\Users\\NEMETH\\Desktop\\greenfox\\znemeth\\Week_02\\day-3\\copy_file\\";
    myfile2.open(path2 + fi2);


    myfile2.close();

}



int main() {

    std::string filename_copy;
    std::string filename_paste;

    std::cout<< "Copy this file: " << std::endl;
    std::cin>> filename_copy;

    std::cout<< "The name of the new file: " << std::endl;
    std::cin>> filename_paste;

    kopi(filename_copy, filename_paste);

    return 0;
}