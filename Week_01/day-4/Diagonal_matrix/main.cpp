#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    int a;
    std::cout << "Write 1 number: " << std::endl;
    std::cin >> a;


    int diag[a][a];

    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++) {
            if (i == j) {
                diag[i][j] = 1;
            } else {
                diag[i][j] = 0;
            }
        }
    }



    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++) {
                std::cout<< diag[i][j] << " ";
            }
            std::cout << std::endl;
        }


    return 0;
}