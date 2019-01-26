#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[5] = {3, 4, 5, 6, 7};

    int b = sizeof(aj)/sizeof(aj[0]);
    for (int i = 0; i < b; i= i+1){
        int c = b - 1 - i;
        //aj[b]=aj[i];
        std::cout << aj[c] << std::endl;
    }

    return 0;
}