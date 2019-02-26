#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct
{
    float x;
    float y;
} point_t;

point_t create_point(float point_x, float point_y)
{
    point_t sample;
    sample.x = point_x;
    sample.y = point_y;
    return sample;
}

float distance(point_t point1, point_t point2)
{
    return (float) sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

int main()
{
    point_t p1 = create_point(1, 1);
    point_t p2 = create_point(1, 2);
    float dist = distance(p1, p2);
    printf("The distance between the 2 points: %.3f", dist);
    return 0;
}