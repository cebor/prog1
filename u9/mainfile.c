/*******************************************************************
// Programm    : Eurotest                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung von Euro-Banknoten Seriennummern
// Änderungen  : 21.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include <ctype.h>
#include "funktionen.h"

#define LEN 255


int main ()
{
	char sn[LEN];
	
	/*
	TESTPROGRAMM Aufgabe 1b.
	int i;
	char *sn[] = {"P02571225193", "A96412454878", "G21546326946", "F78421545466"};
	for (i = 0; i <= 3; i++)
	{
		printf("s/n: %s\n", sn[i]);
		printf("dsum: %d\n", digitsum(sn[i]));
	}
	*/

	strich(50,'-');
	printf("Eurotest\n");
	strich(50,'-');

	input(sn, LEN); // eine sn einlesen und prüfen

	printf("\nServus! \n");
	/*system("pause");*/
	return 0;
}
