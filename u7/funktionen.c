/*******************************************************************
// Programm    : Zahlenraten / Funktionen                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 7.11.2012                                           
// Aufgabe     : Benutzer muss Zahl zwischen 1 und 100 erraten
// Änderungen  : 7.11.2012
*******************************************************************/
#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include "funktionen.h"

/* globale Konstanten für boolesche Ausdrücke */
const int FALSE = 0;
const int TRUE = 1;

void zahlenraten (int MaxZahl)
{
	int rnd, wdh;

	do
	{
		/* initialize random seed: */
		srand(time(NULL));

		/* generate random number: */
		rnd = rand() % MaxZahl + 1;

		rate(rnd);

		wdh = nochmal();

	} while (wdh == TRUE);
}

void rate (int compZahl)
{
	int n;

	printf("Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht. Welche ist es?\n");

	do
	{
		printf("> ");
		scanf("%d", &n);

		if (n < compZahl)
			printf("Die ist zu klein!\n");
		else if (n > compZahl)
			printf("Die ist zu gross!\n");
		else
			printf("Richtig!\n");

	} while (n != compZahl);
}

int nochmal (void)
{
	int rtn;
	char jn;

	do
	{
		printf("Nochmal spielen? (j/n)\n");
	
		scanf(" %c", &jn);

		if (jn == 'j' || jn == 'J')
			rtn = TRUE;
		else if (jn == 'n' || jn == 'N')
			rtn = FALSE;
		else
			rtn = -1;
	
	} while (rtn == -1);
	
	return rtn;
}

void strich (int n, char c) // gibt n mal das Zeichen c aus
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}
