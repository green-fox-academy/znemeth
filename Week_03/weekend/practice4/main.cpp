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



class Subt {
private:
    int negyedik;

public:
    int subtract (Sum &summing){
        //int harmadik;
        negyedik = harmadik * 100;
        return negyedik;

    }

};


int main() {

    int x, y;
    std::cout << "1. number: " << std::endl;
    std::cin >> x;
    std::cout << "2. number: " << std::endl;
    std::cin >> y;

    Subt ob1;
    std::cout << "Result: " << ob1.subtract() << std::endl;

    return 0;
}