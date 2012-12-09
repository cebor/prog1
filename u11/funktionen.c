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

void calcPolygons(polygon_t data[], mainParameters_t params)
{
	int i;

	for (i = 0; i < (params.max - params.min); ++i)
	{
		data[i].corners  = i + params.min;
		data[i].side     = 2 * params.radius * sin(PI / data[i].corners);
		data[i].area     = data[i].corners * data[i].side * data[i].side / (4 * tan(PI / data[i].corners));
		data[i].variance = params.radius * params.radius * PI - data[i].area;
	}
}

void outputPolygons(polygon_t data[], int n_Lines)
{
	int i;

	printf("Anzahl Ecken    Seitenlaenge    Flaeche         Abweichung zu Kreisflaeche\n");

	for (i = 0; i < n_Lines; ++i)
	{
		printf("%3d %20.2lf %14.2lf %20.2lf\n", data[i].corners, data[i].side, data[i].area, data[i].variance);
	}
}
