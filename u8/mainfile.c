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
	int primzahlen[ARRAY_LIMIT + 1];

	/* Aussieben */
	sieb (ARRAY_LIMIT + 1, primzahlen);

	strich(50,'-');
	printf("Sieb des Eratosthenes\n");
	strich(50,'-');

	/* Output */
	ausgabe (ARRAY_LIMIT + 1, primzahlen);

	printf("\nServus! \n");
	/*system("pause");*/
	return 0;
}
