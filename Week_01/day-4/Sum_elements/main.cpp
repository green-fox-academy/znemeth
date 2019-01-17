#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element

    int r[] = {54, 23, 66, 12};
    int f;
    f = r[1] + r[2];

    std::cout << "The sum of 2. and 3. element: " << f << std::endl;



    return 0;
}