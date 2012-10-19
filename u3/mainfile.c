//*******************************************************************
// Programm    : Dreieck                                          
// Verfasser   : Schmidt                                           
// Datum       : Urprogramm: 11.10.2012                                          
// Eingabe     : Seite + Winkel eines rechtwinkligen Dreiecks                            
// Verarbeitung: Berechnung aller Seiten und Winkel                   
// Ausgabe     : Ergebnis als Tabelle
// Änderungen  : 11.10.2012
//*******************************************************************

// Einbinden von nötigen Header-Dateien                              
#include <stdio.h>    // Standard Input/ Output  z.B. scanf, printf
#include <stdlib.h>   // Standard-Bibliothek, z.B. für system
#include <math.h>     // Standard-Bibliothek für math. Funktionen z.B. sqrt
#include <ctype.h>
#include "mainfile.h" // eigene Header-Datei mit Funktionsprototypen


int main() // Beginn Hauptprogramm          **************************
{
	// Aufgabe: Dreieck
	dreieck();

	// system("pause");
	return 0;
} //***************** Ende Hauptprogramm ***************************

// Definition der benötigten Funktionen      

void dreieck(void)
{
	double a;  // Seitenlänge von Seite a
	double alpha_deg;  // Winkel in Grad
	double b;
	double beta_deg;
	double c;
	double gamma_deg = 90;

	int a_floor, b_floor, c_floor;
	int a_ceil, b_ceil, c_ceil;
	int a_round, b_round, c_round;

	// Error Var
	int err;

	// Dialogeröffnung 
	strich(50,'-');
	printf ("Rechtwinkliges Dreieck\n");
	strich(50,'-');

	// Seite/Winkel einlesen
	do
	{
		int i = 0;
		char side[100];

		printf("Bitte Laenge Seite a eingeben: ");

		// scanf("%lf", &a);

		fgets(side, 100, stdin);

		// check for alpha
		err = 0;
		while (side[i] != '\0') {
			if (isalpha(side[i])) err = 1;
			i += 1;
		}

		a = strtod(side, NULL);

		if (err == 1)
			printf("No Chars !!!\n");
		else if (a <= 0)
			printf("Beachte: a > 0 !!!\n");
	} while (err == 1 || a <= 0);

	do
	{
		int i = 0;
		char angel[100];

		printf("Bitte Winkel Alpha in Grad eingeben: ");

		// scanf("%lf", &alpha_deg);

		fgets(angel, 100, stdin);

		// check for alpha
		err = 0;
		while (angel[i] != '\0') {
			if (isalpha(angel[i])) err = 1;
			i += 1;
		}

		alpha_deg = strtod(angel, NULL);

		if (err == 1)
			printf("No Chars !!!\n");
		else if (alpha_deg >= 90 || alpha_deg <= 0)
			printf("Beachte: 0 < Winkel < 90 !!!\n");
	} while (err == 1 || alpha_deg >= 90 || alpha_deg <= 0);

	// Berechnung aller Seiten und Winkel
	b = a / tan(deg2rad(alpha_deg));
	c = a / sin(deg2rad(alpha_deg));

	beta_deg = 90 - alpha_deg;


	// speichern aller Ergebnisse in einer neuen Variablen

	// abrunden aller Seiten auf die nächste ganze Zahl
	a_floor = floor(a);
	b_floor = floor(b);
	c_floor = floor(c);

	// aufrunden aller Seiten auf die nächste ganze Zahl
	a_ceil = ceil(a);
	b_ceil = ceil(b);
	c_ceil = ceil(c);

	// (korrektes) runden aller Seiten auf die nächste ganze Zahl
	a_round = round2(a);
	b_round = round2(b);
	c_round = round2(c);

	// Ausgabe aller Seiten und Winkel
	printf("       2 NK-Stellen   gerundet   abgerundet   aufgerundet\n");
	
	strich(57,'-');

	printf("a        %10.2f %10d   %10d    %10d\n", a, a_round, a_floor, a_ceil);
	printf("b        %10.2f %10d   %10d    %10d\n", b, b_round, b_floor, b_ceil);
	printf("c        %10.2f %10d   %10d    %10d\n", c, c_round, c_floor, c_ceil);

	printf("Alpha (Grad) %6.2f\n", alpha_deg);
	printf("Beta  (Grad) %6.2f\n", beta_deg);
	printf("Gamma (Grad) %6.2f\n", gamma_deg);
	
	printf("Alpha (rad) %7.3f\n", deg2rad(alpha_deg));
	printf("Beta  (rad) %7.3f\n", deg2rad(beta_deg));
	printf("Gamma (rad) %7.3f\n", deg2rad(gamma_deg));
}

// Eingabe: w_deg, Winkel in Grad
// Ausgabe: w_rad, Winkel in rad
double deg2rad (double w_deg)
{
	double w_rad = 0.0;
	// Grad in rad umrechnen, Ergebnis in w_rad
	w_rad = w_deg * (PI/180);

	return w_rad;
}

// gibt n mal das Zeichen c aus
void strich (int n, char c) 
{
	int i;
	for (i=1; i<=n; i++)
		printf("%c", c);
	printf("\n");
}

// eigene Round Function
int round2 (double x) {
	int y;
	x = x + 0.5;
	y = (int) x;
	return y;
}
