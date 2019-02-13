#include <iostream>
#include <vector>

int main()
{/*
    std::vector<std::vector<int>> matrix1 = {{1, 0},
                                             {0, 2}};

    std::vector<std::vector<int>> matrix2 = {{0, 5},
                                             {0, 0}};
*/
    std::vector<std::vector<int>> matrix1 = {{1, 0, 0},
                                             {0, 2, 2},
                                             {0, 2, 1}};

    std::vector<std::vector<int>> matrix2 = {{0, 5, 9},
                                             {0, 0, 0},
                                             {0, 0, 9}};

    std::cout << "Your first matrix: " << std::endl;
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1.size(); ++j) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << "\n";
    };

    std::cout << "Your second matrix: " << std::endl;
    for (int i = 0; i < matrix2.size(); ++i) {
        for (int j = 0; j < matrix2.size(); ++j) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << "\n";
    };

    std::cout << "Size of first matrix: " << matrix1.size() << std::endl;
    std::cout << "Size of second matrix: " << matrix2.size() << std::endl;

    if (matrix1.size() == matrix2.size()) {
        std::cout << "The 2 matrices have the same size, cool!" << std::endl;
    } else {
        std::cout << "Ooooops! The matrices have different sizes!" << std::endl;
    }

    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1.size(); ++j) {
            if (matrix1[i][j] >= matrix2[i][j]) {
                matrix1[i][j] = matrix1[i][j];
            } else {
                matrix1[i][j] = matrix2[i][j];
            }
        }
    }

    std::cout << "Your NEW matrix: " << std::endl;
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1.size(); ++j) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << "\n";
    };

    return 0;
}