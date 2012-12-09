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

	params.min = 3;
	params.max = 200;
	params.radius = 3.2;

	polygons = malloc(sizeof(polygon_t) * (params.max - params.min));

	strich(50,'-');
	printf("Flaeche regelmaessiger Polygone\n");
	strich(50,'-');

	calcPolygons(polygons, params);
	
	outputPolygons(polygons, params.max - params.min);

	printf("\nServus! \n");
	/*system("pause");*/
	return 0;
}
