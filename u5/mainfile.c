/*******************************************************************
/ Programm    : Bruchrechnung                                         
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 24.10.2012                                          
/ Eingabe     : 2 rationale Zahlen                          
/ Verarbeitung: diverse Berechnungen                   
/ �nderungen  : 24.10.2012
/ *******************************************************************/

/* Einbinden von n�tigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
/*#include <stdlib.h>*/   /* Standard-Bibliothek, z.B. f�r system       */
#include "mainfile.h"


int main()
{
	struct Fraction_s f1, f2;

	// 1. Bruch
	printf("Bitte Zaehler und Nenner Bruch 1 eingeben: ");
	scanf("%d %d", &f1.num, &f1.deno);


	// 2. Bruch
	printf("Bitte Zaehler und Nenner Bruch 1 eingeben: ");
	scanf("%d %d", &f2.num, &f2.deno);


	printf("%d / %d\n", f1.num, f1.deno);
	printf("%d / %d\n", f2.num, f2.deno);

	printf("%d / %d\n", pro(f1, f2).num, pro(f1, f2).deno);

	printf("%d / %d\n", quo(f1, f2).num, quo(f1, f2).deno);

	/*system("pause");*/
	return 0;
}

struct Fraction_s pro (struct Fraction_s x, struct Fraction_s y)
{
	x.num = x.num * y.num;

	x.deno = x.deno * y.deno;

	return x;
}

struct Fraction_s sum (struct Fraction_s x, struct Fraction_s y)
{

}

struct Fraction_s quo (struct Fraction_s x, struct Fraction_s y)
{
	x.num	= x.num  * y.deno;

	x.deno	= y.num * x.deno;

	return x;
}

struct Fraction_s dif (struct Fraction_s x, struct Fraction_s y)
{

}
