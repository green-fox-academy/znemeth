#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
    std::ifstream fileName("../usage.txt");
    std::string word = "mentor";
    std::string str;
    getline(fileName, str);
    getline(fileName, word, );

    std::stringstream ss(str);
    int cnt = 0;
    while (ss >> str) {
        if (str == word)
            cnt++;
    }
    std::cout << cnt << "\n";
    return 0;
}