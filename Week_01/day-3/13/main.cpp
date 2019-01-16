#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables
    int left = (24*60*60)-(currentHours*60*60 + currentMinutes*60 + currentSeconds) ;
    std::cout<< "Remaining time in sec: " << left << std::endl;
    return 0;
}