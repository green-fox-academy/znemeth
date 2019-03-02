#include <stdio.h>

int main()
{

    int number;

    printf("Un numero tra 1 e 5: \n");
    scanf("%d", &number);

    switch (number) {
        case 1 :
            printf("Lunedi\n");
            break;
        case 2 :
            printf("Martedi\n");
            break;
        case 3 :
            printf("Mercoledi\n");
            break;
        case 4 :
            printf("Giovedi\n");
            break;
        case 5 :
            printf("Venerdi\n");

            // default :
            // printf("Sabato o Domenica\n");

            return 0;
    }
}