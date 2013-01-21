#include "tt_poly.h"
#include "polynom.h"
#include "inf1.h"
#include <stdlib.h>

int main()
{
	int n;
	int *k;
	double x, y;


	EinlesenGrad(&n);

	k = (int*) malloc(sizeof(int) * (n+1));
	Assert(k != NULL, "Malloc fehlgeschlagen!");

	EinlesenKoeff(n, k);

	EinlesenArg(&x);

	y = PolynomWert(n, k, x);

	printf("Der Polynomwert an der Stelle x= %.2lf ist y= %.2lf\n", x, y);

	free(k);


	printf("Press Enter...\n");
	while (getchar() != '\n');


	// Einkommentieren zum Start des Testtreibers für Polynomwertberechnung (Aufgabe 1)
	tt_polyWert();
	
	// Einkommentieren zum Start des Testtreibers für Nullstellenberechnung (Aufgabe 2)
	tt_polyAbl();

	return 0;
}
