#include <iostream>

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    std::cout<< "How many numbers do you want to store?" << std::endl;
    int a;
    std::cin >> a;
    //std::cout << a << std::endl;

    int input[a];
    for (int i=0; i<a; i++){
        std::cin>> input[i];
    }

    int size = sizeof(input) / sizeof(input[0]);

    int numb = 0;
    for (int i=0; i<size; i++){
        if (input[i] > numb) {
            numb = input[i];
        }
    }

    std::cout << "The value of the biggest number is: " << numb << std::endl;
    std::cout << "The address of the biggest number is: "<< &numb << std::endl;


    return 0;
}