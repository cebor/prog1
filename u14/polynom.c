#include "polynom.h"
#include <math.h>    // wegen math. Funktionen 
#include <stdio.h>


void EinlesenGrad (int *n)
{
	printf("Bitte Polynomgrad eingeben: ");
	scanf("%d", n);
}

void EinlesenKoeff (int n, int k[])
{
	int i;

	printf("Bitte Polynomkoeffizienten einzeln eingeben!\n");
	for (i = 0; i < n+1; i++)
	{
		printf(" a (%d) = ", i);
		scanf("%d", &k[i]);
	}
}

void EinlesenArg (double *x)
{
	printf("Bitte Argument eingeben: ");
	scanf("%lf", x);
}

// Berechnung des Wertes des Polynoms a[0] + a[1] x + ... + a[n] x hoch n
double PolynomWert (const int n, const int a[], const double x)
{
	int i;
	double y;
	y = a[n];

	for (i = n-1; i >= 0; --i)
	{
		y = y * x + a[i];
	}

	return y;
}

// liest Startwert f?r Newton-Iteration ein  
void EinlesenStartwert(double * p_start)
{
	printf("Bitte Naeherungswert fuer Nullstelle eingeben: ");
	scanf("%lf",p_start);
}

// Berechnung des Wertes der 1. Ableitung des Polynoms an der Stelle x
double PolyAblWert (const int n, const int a[], const double x)
{
	int i;
	double y;
	y = a[n] * n;
	for (i = n-1; i >= 1; i--)
		y = y * x + i * a[i];
	return y;
}

// Berechnung einer Nullstelle des Polynoms (n, a) aus Startwert s
// status 0: Nullstelle gefunden;1: waagrechte Tangente;2: keine Konvergenz
double Nullstelle (const int n, const int a[],const double s, int * status)
{
	const double eps = 0.0001; // Genauigkeit für Iteration  
	const double cMax = 100; // Maximale Anzahl von Iterationen  
	int i;         // Zähler für Iterationen  
	double x, y, abl;

	x = s;
	y = PolynomWert(n, a, x);
	// Newton-Iteration   
	i=0;
	*status = 0;
	while ((fabs(y) > eps) && (i <= cMax) && (* status == 0))
	{
		abl = PolyAblWert(n,a,x);
		if (fabs(abl)> eps)
			x = x - y / abl;
		else
			*status = 1;
		y = PolynomWert(n,a,x);
#ifdef TEST
		printf("*Test * %5i %12.5lf %12.5lf %5i\n",i,x,y, *status);
#endif
		i++;
	}
	if (i >= cMax)
		*status = 2;

	return(x);
}
