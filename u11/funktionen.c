/*******************************************************************
// Programm    : Polygon                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "funktionen.h"

#define PI 3.14159265358979323846

void strich (int n, char c) /* gibt n mal das Zeichen c aus */
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

void calcPolygons(polygon_t *data, mainParameters_t params)
{
	int i;

	for (i = 0; i < (params.max - params.min + 1); i++)
	{
		data[i].corners  = i + params.min;
		data[i].side     = 2 * params.radius * sin(PI / data[i].corners);
		data[i].area     = data[i].corners * data[i].side * data[i].side / (4 * tan(PI / data[i].corners));
		data[i].variance = params.radius * params.radius * PI - data[i].area;
	}
}

void outputPolygons(polygon_t *data, int n_Lines)
{
	int i;

	printf("Anzahl Ecken    Seitenlaenge    Flaeche         Abweichung zu Kreisflaeche\n");

	for (i = 0; i < n_Lines; i++)
	{
		printf("%3d %20.2lf %14.2lf %20.2lf\n", data[i].corners, data[i].side, data[i].area, data[i].variance);
	}
}

cl_errors_t scanCommandLine(int argc, char **argv, mainParameters_t *params)
{
	int i;

	for (i = 1; i < argc; i += 2)
	{
		if (argv[i][0] == '-')
		{
			if (strcmp(&argv[i][1], "emin") == 0)
			{
				params->min = atoi(argv[i+1]);
				printf("-emin %d\n", params->min);
			}
			else if (strcmp(&argv[i][1], "emax") == 0)
			{
				params->max = atoi(argv[i+1]);
				printf("-emax %d\n", params->max);
			}
			else if (strcmp(&argv[i][1], "r") == 0)
			{
				params->radius = atof(argv[i+1]);
				printf("-r %g\n", params->radius);
			}
			else
				return CL_UNKOWNPARAM;
		}
		else
			return CL_UNKOWNPARAM;
	}

	if (!params->min || !params->max || !params->radius)
		return CL_PARAMMISSING;
	else if (params->min <= 2)
		return CL_EMINOUTOFRANGE;
	else if (params->max < params->min)
		return CL_EMAXOUTOFRANGE;
	else if (params->radius <= 0)
		return CL_RADIUSINVALID;
	else
		return CL_NOERROR;
}

void printCLError(cl_errors_t err)
{
	switch (err)
	{
		case CL_NOERROR:
			break;
		case CL_EMINOUTOFRANGE:
			printf("-emin <= 0\n");
			usage();
			exit(CL_EMINOUTOFRANGE);
			break;
		case CL_EMAXOUTOFRANGE:
			printf("-emax < -emin\n");
			usage();
			exit(CL_EMAXOUTOFRANGE);
			break;
		case CL_RADIUSINVALID:
			printf("-r < 0.0\n");
			usage();
			exit(CL_RADIUSINVALID);
			break;
		case CL_PARAMMISSING:
			printf("missing parameter\n");
			usage();
			exit(CL_PARAMMISSING);
			break;
		case CL_UNKOWNPARAM:
			printf("unknown parameter\n");
			usage();
			exit(CL_UNKOWNPARAM);
			break;
		default:
			exit(0);
	}
}

void usage()
{
	printf("\n");
	printf("Usage: polygon\n");
	printf("-emin:     minimum corners\n");
	printf("-emax:     maximum corners\n");
	printf("-r:        radius\n");
}
