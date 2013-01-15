//*******************************************************************
// Modul     : inf1.c                                              
// Verfasser : Feindor / Schmidt                                         
// Datum     : Urprogramm 1.10.1996                                           
// Inhalt    : Hilfsfunktionen f�r Inf 1                           
// �nderungen: 5.11.2010
//*******************************************************************
// Einbinden von n�tigen Header-Dateien                      
#include "inf1.h"

// Hilfsfunktionen                                                   
void strich (int n, char c)  // gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c",c);

	printf("\n");
}

void dialog(char *Ueberschrift) // gibt �berschrift aus 
{
	strich (50, '-'); // Aufruf der eben definierten Funktion
	printf("%s \n", Ueberschrift);
	strich (50, '-');
}

// die folgenden Funktionen kommen sp�ter dazu
void Assert(bool ok, char *meldung) // gibt Fehlermeldung, wenn nicht ok 
{
	if (ok) return;

	printf("\n*** Fehlerabbruch: *** %s *** \n", meldung);
	// Hier k�nnen beliebige weitere Aktionen erfolgen

	system("pause");
	exit(1);
}

/*
// kopiert in ziel aus quelle ab anzahl character
void copy (char * ziel, char * quelle, short ab, short anzahl) 
{
// hier Text einf�gen
}
*/


