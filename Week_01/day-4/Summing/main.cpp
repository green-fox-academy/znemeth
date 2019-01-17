#include <iostream>
#include <string>

int sum(int b){
    int s = 0;
    for (int i = 0; i <= b; i+=1){
        s = s + i;
    }
    return s;
}

int main(int argc, char* args[]) {

    // - Write a function called `sum` that sums all the numbers
    //   until the given parameter and returns with an integer

    int a;
    std::cout << "Write a number: " << std::endl;
    std::cin>> a;
    sum(a);
    std::cout << "The number: " << sum(a) << std::endl;

    return 0;
}