#include <iostream>
#include <vector>

std::vector<std::vector<int>>
calculateMaxMatrix(std::vector<std::vector<int>> input1, std::vector<std::vector<int>> input2)
{
    std::vector<std::vector<int>> result;
    result.resize(input1.size());

    for (int i = 0; i < input1.size(); ++i) {
        result[i].resize(input1[i].size());
        for (int j = 0; j < input1.size(); ++j) {
            if (input1[i][j] > input2[i][j]) {
                result[i][j] = input1[i][j];
            } else {
                result[i][j] = input2[i][j];
            }
        }
    }

    std::cout << "Your NEW matrix: " << std::endl;
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result.size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
    return result;
};

int main()
{
    std::vector<std::vector<int>> input1, input2;

    input1 = {
        {3, 2},
        {3, 2}
    };

    input2 = {
        {4, 0},
        {6, 1}
    };

    calculateMaxMatrix(input1, input2);

    return 0;
}