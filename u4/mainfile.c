/*******************************************************************
/ Programm    : Datentypen                                          
/ Verfasser   : Schmidt                                           
/ Datum       : Urprogramm: 17.10.2012                                          
/ Eingabe     : Vier Zeichen                            
/ Verarbeitung: diverse Berechnungen                   
/ Änderungen  : 17.10.2012
/*******************************************************************/

/* Einbinden von nötigen Header-Dateien                               */
#include <stdio.h>    /* Standard Input/ Output  z.B. scanf, printf */
#include <stdlib.h>   /* Standard-Bibliothek, z.B. für system */


char kleinstesZeichen(char c[]);
char groesstesZeichen(char c[]);

int main()
{
	char input[4];
	int midint, delta;
	float midfl;

	printf("Bitte geben Sie vier einzelne Zeichen ein:");

	scanf("%c %c %c %c", &input[0], &input[1], &input[2], &input[3]);

	midint = (input[0] + input[1] + input[2] + input[3]) / 4;
	midfl = (input[0] + input[1] + input[2] + input[3]) / 4.0;

	delta = groesstesZeichen(input) - kleinstesZeichen(input);

	printf("Eingegeben wurden:       %c %c %c %c\n", input[0], input[1], input[2], input[3]);
	printf("ASCII Codes:             %d %d %d %d\n", input[0], input[1], input[2], input[3]);
	printf("ASCII Code (Mittel,int): %d\n", midint);
	printf("ASCII Code (Mittel,int): 0x%x\n", midint);
	printf("ASCII Code (Mittel,fl):  %f\n", midfl);
	printf("\"Mittleres\" Zeichen:     %c\n", midint);
	printf("Kleinstes Zeichen:       %c\n", kleinstesZeichen(input));
	printf("Groesstes Zeichen:       %c\n", groesstesZeichen(input));
	printf("Abstand Min/Max:         %d Zeichen\n", delta);


	/*system("pause");*/
	return 0;
}

char kleinstesZeichen(char c[])
{
	char min;
	int i;

	min = c[0];

	for (i = 0; i < 4; i++) {
		if (c[i] < min) min = c[i];
	}

	return min;
}

char groesstesZeichen(char c[])
{
	char max;
	int i;

	max = c[0];

	for (i = 0; i < 4; i++) {
		if (c[i] > max) max = c[i];
	}

	return max;
}
