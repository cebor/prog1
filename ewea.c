#include <stdio.h>
#include <math.h>

typedef struct
{
	int d;
	int x;
	int y;
} ewea_t;

ewea_t ewea (int, int);

int main(int argc, char const *argv[])
{
	ewea_t a;

	a = ewea(128,34);

	printf("ggT: %2d\n", a.d);
	printf("x: %4d\n", a.x);
	printf("y: %4d\n", a.y);
	
	return 0;
}

ewea_t ewea (int a, int b)
{
	ewea_t rtn;

	int tmp;

	if (b == 0)
	{
		rtn.d = a;
		rtn.x = 1;
		rtn.y = 0;
		return rtn; 
	}
	
	rtn = ewea(b, a % b);

	tmp = rtn.x;
	rtn.x = rtn.y;
	rtn.y = tmp - floor(a/b)*rtn.y;

	return rtn;
}
