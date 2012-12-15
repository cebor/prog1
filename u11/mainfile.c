/*******************************************************************
// Programm    : Polygon                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 5.12.2012                                           
// Aufgabe     : Berechnung Fläche regelmäßiger Polygone
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "funktionen.h"

int main (int argc, char **argv)    
{
	mainParameters_t params;
	polygon_t *polygons;
	cl_errors_t error;

	error = scanCommandLine(argc, argv, &params);

	printCLError(error);

	polygons = malloc(sizeof(polygon_t) * (params.max - params.min + 1));
	if (polygons == NULL) exit(0);

	strich(50,'-');
	printf("Flaeche regelmaessiger Polygone\n");
	strich(50,'-');

	calcPolygons(polygons, params);
	
	outputPolygons(polygons, params.max - params.min + 1);

	free(polygons);

	printf("\nServus! \n");
	/*system("pause");*/
	return 0;
}
