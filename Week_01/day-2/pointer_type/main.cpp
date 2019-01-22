#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *a_Ptr = &a;
    double *b_Ptr = &b;
    std::string *name_Ptr = &name;

    std::cout << " The value of pointer a: "<< a_Ptr <<std::endl;
    std::cout << " The value of pointer b: "<< b_Ptr <<std::endl;
    std::cout << " The value of pointer name: "<< name_Ptr <<std::endl;

    std::cout << " The value of pointer a: "<< *a_Ptr <<std::endl;
    std::cout << " The value of pointer b: "<< *b_Ptr <<std::endl;
    std::cout << " The value of pointer name: "<< *name_Ptr <<std::endl;

    return 0;
}