#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};

        //sizeof(p1) byte-ban adja meg

    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`
    if ( (sizeof(p1) / sizeof(p1[0])) < (sizeof(p2) / sizeof(p2[0])) ) {
        std::cout << "The size of p2 is bigger!" << std::endl;
    }

    if ( (sizeof(p1) / sizeof(p1[0])) > (sizeof(p2) / sizeof(p2[0])) ) {
        std::cout << "The size of p1 is bigger!" << std::endl;
    }
    return 0;
}