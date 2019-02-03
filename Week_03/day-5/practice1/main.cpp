#include <iostream>

// Create a function named `IsSymmetric` that takes an n×n integer matrix (list of lists) as parameter
// and returns true, if is that matrix is symmetric (diagonally from top-left to bottom-right)
// or false if it is not
//
// example for symmetric matrix:
// 1 0 1
// 0 2 2
// 1 2 5
//
// example for not symmetric matrix
// 7 7 7
// 6 5 7
// 1 2 1

int main() {
    int A[10][10];
    int i, j, m, n;
    int x = 0;

    std::cout << "Enter the number of rows and columns in the matrix : " << std::endl;
    std::cin >> m;
    std::cin >> n;
    std::cout << "Enter the elements of the matrix: " << std::endl;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            std::cin >> A[i][j];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != A[j][i])
                x = 1;
        }
    }


    if (x == 0)
        std::cout << "The matrix is symmetric. \n";
    else
        std::cout << "It is an asymmetric matrix. \n";

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            std::cout << A[i][j] << " ";
        std::cout << "\n ";
    }
    return 0;
};