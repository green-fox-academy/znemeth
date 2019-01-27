#include <iostream>

int main() {

    /* Write a program where the program chooses a number between 1 and 100.
       The player is then asked to enter a guess.
       If the player guesses wrong,
       then the program gives feedback and ask to enter an other guess until the guess is correct.

       Make the range customizable (ask for it before starting the guessing).
       You can add lives. (optional)*/
    std::cout<< "How many lives do you want to have?" <<std::endl;
    int lives;
    std::cin>> lives;
    int guessnumber;

    int randomnumber = rand() % 100 + 1;

    for (int i=lives; i>0; i--){

        std::cout<< "Guess a number!" << std::endl;
        std::cin>> guessnumber;

        if (guessnumber < randomnumber){
            std::cout<< "Too low! You have " << i-1 << " lives left." << std::endl;
        } else if (guessnumber > randomnumber){
            std::cout<< "Too high! You have " << i-1 << " lives left." << std::endl;
        } else if (guessnumber == randomnumber) {
            std::cout << "You won!" << std::endl;
            }
        }
    return 0;
}