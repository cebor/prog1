/*******************************************************************
// Programm    : Eurotest                                               
// Verfasser   : Schmidt                                             
// Datum       : Urprogramm: 21.11.2012                                           
// Aufgabe     : Prüfung von Euro-Banknoten Seriennummern
// Änderungen  : 21.11.2012
*******************************************************************/

#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <string.h>
#include <ctype.h>
#include "funktionen.h"


void strich (int n, char c) 					// gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

// IsDigitString: String auf Ziffern testen
int isdstr (const char * str)
{
	int i;
	for (i = 0; str[i] != 0; i++)
		if (!isdigit(str[i]))
			return 0;
	return 1;
}

// Quersumme
int digitsum (const char * str)
{
	int i, dsum;

	// erster buchstabe direkt den ascii-wert übernehmen
	dsum = (int) str[0];

	// schleife: aufaddierung der zahlen (bis zum '\0')
	for (i = 1; str[i] != 0; i++)
 		dsum += (int) (str[i] - '0');

	return dsum;
}

// EuroTest
t_errcode eurotest (const char * str)
{
	// error auf ok setzen
	t_errcode err;

	// string länge
	size_t ln = strlen(str);

	// testen
	if (ln < 12)
		err = ec_zukurz;

	else if (ln > 12)
		err = ec_zulang;

	else if (!isupper(str[0]))
		err = ec_LCfalsch;

	else if (!isdstr(&str[1]))
		err = ec_SNkeineZiffer;

	else if (digitsum(str) % 9 != 0)
		err = ec_pz_falsch;

	else
		err = ec_ok;

	return err;
}

// Eine s/n einlesen und prüfen!
void input (char * str, int ln_max)
{
	t_errcode err;

	do
	{
		size_t ln;

		printf("Bitte gib eine euro-s/n ein: ");

		// s/n einlesen
		fgets(str, ln_max, stdin);

		// entferne das mit eingelesene und sinnfreie '\n'
		ln = strlen(str) - 1;
		if (str[ln] == '\n')
			str[ln] = '\0';

		// error-variable
		err = eurotest(str);

		// testen
		if (err == 1)
			printf("Ungültige s/n!\n");

		else if (err == 2)
			printf("s/n zu kurz!\n");

		else if (err == 3)
			printf("s/n zu lang!\n");

		else if (err == 4)
			printf("Falscher Ländercode!\n");

		else if (err == 5)
			printf("Ungültige Zeichen in der s/n!\n");

		else
			printf("%s - OK\n", str);

	} while (err != ec_ok);

}
