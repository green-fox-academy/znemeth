#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main()
{
    std::ifstream fin("../usage.txt");
    int count = 0;
    char ch[20], c[20];

    std::cout << "Enter a word to count:";
    gets(c);

    while (fin) {
        fin >> ch;
        if (strcmp(ch, c) == 0)
            count++;
    }

    std::cout << "Occurrence=" << count << "\n";
    fin.close();

    return 0;
}