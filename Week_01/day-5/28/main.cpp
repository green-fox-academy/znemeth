#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was


        int rows;

        std::cout << "Enter number of rows: " << std::endl;
        std::cin >> rows;

        for(int i = 0; i < rows+1; i++) {
            for(int j = 0; j < i+1; j++)
            {
                std::cout << "*" ;// << std::endl;

            }

            std::cout<<"\n"<< std::endl;
        }
        return 0;
    }