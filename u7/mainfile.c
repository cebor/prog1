/*******************************************************************
// Programm    : Zahlenraten / Hauptdatei                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 7.11.2012                                           
// Aufgabe     : Benutzer muss Zahl zwischen 1 und 100 erraten
// Änderungen  : 7.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include <time.h>
#include "funktionen.h"

int main () 
{
	const int LIMIT = 100;

	srand(time(NULL));  /* Init Random Seed */

	strich(50,'-');
	printf("Zahlenraten\n");
	strich(50,'-');

	zahlenraten(LIMIT);

	printf("Servus! \n");
	/*system("pause");*/
	return 0;
}