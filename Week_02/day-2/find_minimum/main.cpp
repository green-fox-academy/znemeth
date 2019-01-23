#include <iostream>

int findMin (int *numb, int size){

    int *ptr = nullptr;
    int smallval = numb[0];

    for (int i=0; i<size; i++){
        if (numb[i] < smallval) {
            smallval = numb[i];
        }
    }
    ptr = &smallval;
    return *ptr;
}

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    findMin(numbers, size);
    std::cout << "The value of the smallest number is: " << findMin(numbers, size) << std::endl;

    return 0;
}