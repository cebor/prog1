/*******************************************************************
// Programm    : Primzahlen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 13.11.2012                                           
// Aufgabe     : Primzahlberechnung nach Sieb des Eratosthenes
// Änderungen  : 13.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>
#include "funktionen.h"


void strich (int n, char c) /* gibt n mal das Zeichen c aus */
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

void sieb (int limit, int array[])
{
	int i, j;

	for (i = 2; i <= sqrt((float)limit); i++) /* Bis zur Wurzel auf Primzahl prüfen. */
		if (array[i] == PRIM)
			for (j = 2 * i; j <= limit; j += i) array[j] = NICHT_PRIM; /* Alle Vielfachen als Nicht-Primzahl makieren. */
}

void ausgabe (int limit, int array[])
{
	int i;

	for (i = 0; i <= limit; i++)
		if (array[i] == PRIM)
			printf("%d, ", i);
}
