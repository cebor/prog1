#include "tt_poly.h"
#include "polynom.h"
#include "inf1.h"
#include <stdlib.h>

int main()
{
	int n;
	int *k;
	int arg;


	// Einkommentieren zum Start des Testtreibers für Polynomwertberechnung (Aufgabe 1)
	// tt_polyWert();
	
	// Einkommentieren zum Start des Testtreibers für Nullstellenberechnung (Aufgabe 2)
	// tt_polyAbl();


EinlesenGrad(&n);

k = malloc(sizeof(int) * n);
if (k = NULL) 
{
	printf("Kein Speicher !\n");
	exit(0);
}

EinlesenKoeff(n, k);

EinlesenArg(&arg);

	return 0;
}