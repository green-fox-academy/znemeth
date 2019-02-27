#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int calculate_percentile(int **matrix, int percentile)
{

    int percen = percentile / 10;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    //return ;
}

int main()
{
    int m;
    int n;

    printf("Number of rows and columns of the matrix: \n");
    scanf("%d %d", &m, &n);

    int **matrix = (int **) malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }



    int percentile;
    printf("Gimme percentiles: \n");
    scanf("%d", &percentile);

    calculate_percentile(**matrix, percentile);

    return 0;
}