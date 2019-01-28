#include <iostream>
#include <string>

int minimumValuePtr (int *array, int size) {
    int *ptr = nullptr;
    int small1 = array[0];
    for (int i = 0; i < size; i++) {
        if (small1 < 0) {
            if (small1 > array[i]) {
                small1 = array[i];
            }
        }
    }

    int small2= array[0];
    for (int i = 0; i < size; i++) {
        if (small2 > 0) {
            if (small2 > array[i]) {
                small2 = array[i];
            }
        }
    }

    int small;

    if (small1 < abs(small2)){
        small = small1;
    }
    if (small1 > abs(small2)){
        small = small2;
    }

    if (small1 == abs(small2)){
        small = small1;
    }

    if (small1 == 0 || abs(small2) == 0){
        small = small1;
    }


    ptr = &small;
    return *ptr;
}

int main(int argc, char* args[]) {

    int temp [] = {0, 2, 4, -5, -14, -2};
    int size = (sizeof(temp) / sizeof(temp[0]));
   /* if (size == 0){
        std::cout << "No data!" << std::endl;
    }*/

    minimumValuePtr(temp, size);
    std::cout << minimumValuePtr(temp,size) << std::endl;

    return 0;
}