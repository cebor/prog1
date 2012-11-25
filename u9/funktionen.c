/*******************************************************************
// Programm    : Eurotest                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung von Euro-Banknoten Seriennummern
// Änderungen  : 21.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.h"



void strich (int n, char c) 				// gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

// CHAR Digit >> INT
int dtoi (const char c)
{
	char str[2];

	str[0] = c;
	str[1] = '\0';							// "int atoi ( const char * str );" benötigt das '\0' !!

	return atoi(str);
} 

// Quersumme
int digitsum (const char str[])
{
	int i, dsum;

	dsum = (int) str[0];					// erster buchstabe direkt den ascii-wert übernehmen

	for (i = 1; str[i] != '\0'; i++)		// schleife: aufaddierung der zahlen (bis zum '\0')
	{
 		dsum += dtoi(str[i]);
	}

	return dsum;
}
