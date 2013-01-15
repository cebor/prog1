#include "polynom.h"
#include <math.h>    // wegen math. Funktionen 


// Berechnung des Wertes des Polynoms a[0] + a[1] x + ... + a[n] x hoch n
double PolynomWert (const int n, const int a[], const double x)
{
	return 0.0;
}

// Berechnung des Wertes der 1. Ableitung des Polynoms an der Stelle x
double PolyAblWert (const int n, const int a[], const double x)
{
	return 0.0;
}

// Berechnung einer Nullstelle des Polynoms (n, a) aus Startwert s
// status 0: Nullstelle gefunden;1: waagrechte Tangente;2: keine Konvergenz
double Nullstelle (const int n, const int a[],const double s, int * status)
{
	return 0.0;
}

void EinlesenGrad (int *n)
{
	printf("Bitte Polynomgrad eingeben: ");
	scanf("%d", n);
}

void EinlesenKoeff (int n, int *k)
{
	int i;

	printf("Bitte Polynomkoeffizienten einzeln eingeben!\n");
	for (i = 0; i < n; ++i)
	{
		printf(" a (%d) =", i+1);
		scanf("%s", &k[i])
	}
}

void EinlesenArg (int *arg)
{
	printf("Bitte Argument eingeben: ");
	scanf("%d", arg)
}