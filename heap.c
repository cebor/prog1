#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float x;
	float y;
} point_t;


int main (int argc, char **argv)
{
	point_t *abc = malloc(sizeof(point_t));;

	abc->x = 1.5;
	abc->y = 4.5;

	printf("%f, %f \n", abc->x, abc->y);

	free(abc);
}
