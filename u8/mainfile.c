/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "funktionen.h"

#define ARRAY_LIMIT 1000


int main () 
{
	int primzahlen[ARRAY_LIMIT] = {NICHT_PRIM, NICHT_PRIM}; /* 0 und 1 als NICHT_PRIMT makieren */
	int i;

	/* Alle Zahlen ab 2 als PRIM makieren */
	for (i = 2; i < ARRAY_LIMIT; i++)
	{
		primzahlen[i] = PRIM;
	}

	/* Aussieben */
	sieb (ARRAY_LIMIT, primzahlen);

	strich(50,'-');
	printf("Sieb des Eratosthenes\n");
	strich(50,'-');

	/* Output */
	ausgabe (ARRAY_LIMIT, primzahlen);

	printf("\nServus! \n");
	/*system("pause");*/
	return 0;
}
