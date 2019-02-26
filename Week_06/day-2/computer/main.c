#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer
{
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct
{
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer c;
    c.cpu_speed_GHz = 2.00;
    c.bits = 64;
    c.ram_size_GB = 8;

    Notebook n;
    n.ram_size_GB = 4;
    n.bits = 32;
    n.cpu_speed_GHz = 1.80;

    printf("Computer ram: %d, bit: %d, cpu in GHz: %.2f \n", c.ram_size_GB, c.bits, c.cpu_speed_GHz);
    printf("Notebook ram: %d, bit: %d, cpu in GHz: %.2f", n.ram_size_GB, n.bits, n.cpu_speed_GHz);

    return 0;
}