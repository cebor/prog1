/*******************************************************************
// Programm    : exp1
// Verfasser   : Feindor/Schmidt
// Datum       : Urprogramm: 1.10.1996
// Eingabe     : obere und untere Grenzen
// Verarbeitung: Berechnung von Funktionen, Zählen, Summieren
// Ausgabe     : Zahlentabellen
// Änderungen  : 30.10.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <math.h>   /* Standard-Bibliothek für math. Funktionen  z.B. sqrt */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "exp.h"


int main ()
{
	int limit;

	line(50,'-');
	printf ("Exp: Berechnung von einfachen Funktionen\n");
	line(50,'-');

	limit = limitInput(20);		/* Grenze einlesen */

	tableOutput(limit);			/* Tabelle ausgeben */

	printf("Servus! \n");
	/*system("pause");*/
	return 0;
}


/* gibt n mal das Zeichen c aus */
void line (int n, char c)
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}

int limitInput (int cMax)
{
	int limit;

	do
	{
		printf("Bitte positive obere Grenze eingeben (ganzzahlig <= 20): ");

		scanf("%d", &limit);

		if (limit > cMax)
			printf("Zahl muss ganzzahlig <= 20 sein !!!\n");
	} while (limit > cMax);

	return limit;
}

void tableOutput (int limit)
{
	int i;

	line(75,'-');
	printf("   i    1/i Summe(1/i)                   i!            1/i!  Naeherung e   \n");
	line(75,'-');

	for (i = 1; i <= limit; i++)
	{
		printf("%4d %.4lf %10.7lf %20ld %.14lf %.12lf\n", i, 1/(double)i, summation(i, 0), fact(i), 1/(double)fact(i), summation(i, 1));
	}
}

/* Fakultät berechnen */
long int fact (unsigned int n)
{
	if (n <= 1)
		return 1;
	return n * fact(n-1);
}

/* Summen berechen */
double summation (int n, int e)
{
	double sum = 0;

	if (!e)
	{
		while (n >= 1)
		{
			sum += 1/(double)n--;
		}
	}
	else
	{
		while (n >= 0)
		{
			sum += 1/(double)fact(n--);
		}
	}

	return sum;
}
