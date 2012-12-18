/*
Programm kann mit Parameter -a und -b gestartet Werden
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
	int a;
	int b;
} mainParameters_t;

typedef struct
{
	int d;
	int x;
	int y;
} ewea_t;

ewea_t ewea (int, int);
void scanCommandLine(int argc, char const **argv, mainParameters_t *params);

int main (int argc, char const *argv[])
{
	ewea_t a;
	mainParameters_t params;

	scanCommandLine(argc, argv, &params);

	a = ewea(params.a, params.b);

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
	rtn.y = tmp - floor(a/b) * rtn.y;

	return rtn;
}

void scanCommandLine(int argc, char const **argv, mainParameters_t *params)
{
	int i = 1;

	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				case 'a':
					i++;
					params->a = atoi(argv[i]);
					break;
				case 'b':
					i++;
					params->b = atoi(argv[i]);
					break;
				default:
					printf("Falsche Parameter!!!\n");
					exit(0);
			}
			i++;
		}
		else
		{
			printf("Falsche Parameter!!!\n");
			exit(0);
		}
	}
}
