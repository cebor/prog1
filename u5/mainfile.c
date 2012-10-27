/*******************************************************************
/ Programm    : Bruchrechnung                                         
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 24.10.2012                                          
/ Eingabe     : 2 rationale Zahlen                          
/ Verarbeitung: diverse Berechnungen                   
/ Änderungen  : 24.10.2012
/ *******************************************************************/

/* Einbinden von nötigen Header-Dateien                             */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system       */
#include "mainfile.h"


int main()
{
	struct Fraction_s f1, f2;

	/* 1. Bruch */
	printf("Bitte Zaehler und Nenner Bruch 1 eingeben: ");
	scanf("%d %d", &f1.num, &f1.deno);

	/* 2. Bruch */
	printf("Bitte Zaehler und Nenner Bruch 2 eingeben: ");
	scanf("%d %d", &f2.num, &f2.deno);


	printf("%d/%d * %d/%d = %d/%d\n", f1.num, f1.deno, f2.num, f2.deno, pro(f1, f2).num, pro(f1, f2).deno);

	printf("%d/%d / %d/%d = %d/%d\n", f1.num, f1.deno, f2.num, f2.deno, quo(f1, f2).num, quo(f1, f2).deno);

	printf("%d/%d + %d/%d = %d/%d\n", f1.num, f1.deno, f2.num, f2.deno, sum(f1, f2).num, sum(f1, f2).deno);

	printf("%d/%d - %d/%d = %d/%d\n", f1.num, f1.deno, f2.num, f2.deno, dif(f1, f2).num, dif(f1, f2).deno);


	/*system("pause");*/
	return 0;
}

/* produkt */
struct Fraction_s pro (struct Fraction_s x, struct Fraction_s y)
{
	x.num  = x.num * y.num;
	x.deno = x.deno * y.deno;

	x = reduce(x);

	return x;
}

/* summe */
struct Fraction_s sum (struct Fraction_s x, struct Fraction_s y)
{
	x.num  = x.num * y.deno + y.num * x.deno;
	x.deno = x.deno * y.deno;

	x = reduce(x);

	return x;
}

/* quotient */
struct Fraction_s quo (struct Fraction_s x, struct Fraction_s y)
{
	x.num  = x.num * y.deno;
	x.deno = y.num * x.deno;

	x = reduce(x);

	return x;
}

/* differenz */
struct Fraction_s dif (struct Fraction_s x, struct Fraction_s y)
{
	x.num  = x.num * y.deno - y.num * x.deno;
	x.deno = x.deno * y.deno;

	x = reduce(x);

	return x;
}

/* ggt */
int gcd (int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a%b == 0) return b;
	if (a < b) return gcd(b, a);
	else return gcd(b, a%b);
}

/* kürzen */
struct Fraction_s reduce (struct Fraction_s x)
{
	int divisor;

	divisor = gcd(x.num, x.deno);

	x.num  = x.num / divisor;
	x.deno = x.deno / divisor;

	/* minus auf eine seite */
	if ((x.deno < 0 && x.num > 0) || (x.deno < 0 && x.num < 0))
	{
		x.deno *= -1;
		x.num  *= -1;
	}

	return x;
}
