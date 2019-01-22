#include <iostream>

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};

    int size = sizeof(numbers) / sizeof(numbers[0]);
    int numb = 0;
    for (int i=0; i<size; i++){
        if (numbers[i] > numb) {
            numb = numbers[i];
        }
    }


    std::cout << "The value of the smallest number is: " << numb << std::endl;


    return 0;
}