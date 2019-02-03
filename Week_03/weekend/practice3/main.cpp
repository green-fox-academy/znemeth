#include <iostream>

class Sum {
private:
    int elso;
    int masodik;

public:
    Sum(int aa, int bb)
    {
        elso = aa;
        masodik = bb;
    }

    int summing()
    {
        int harmadik = elso + masodik;
        return harmadik;
    }
};


int main() {

    int x, y;
    std::cout << "1. number: " << std::endl;
    std::cin >> x;
    std::cout << "2. number: " << std::endl;
    std::cin >> y;

    Sum ob1(x, y);
    std::cout << "Result: " << ob1.summing() << std::endl;

    return 0;
}