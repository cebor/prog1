//*********************************************************************
// Source File : tt_liste02.c
// Testtreiber für ADT liste (einfach verkettete Liste)
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 11.1.2011 J. Schmidt
//*********************************************************************
#include "liste02.h"

// Anzahl der Elemente
#define  N 10  

// falls man zusehen möchte
#define TEST     

char testListe[N][LAENGE];   // globale Testdaten N Elemente der Standard-LAENGE

// Generieren von zufälligen globalen Testdaten
void GenTestdaten() 
{	
	int i, z;
	srand((int) time(0)); // Start des Zufallsgenerators
	for (i = 0; i < N; i++)
	{
		z = rand() % (10 * N);    // Zufallszahl 0..10N
		sprintf (testListe[i], "Testelement %5i", z); // füllen Elemente in testListe
	}
}

void insertData(t_Listenkopf *li)
{
	int i;

	for (i = 0; i < N; i++)
	{
		einfuegenElement(li, testListe[i]);
		printListe(li);
		printf("Element %s eingefügt.\n", testListe[i]);

		#ifdef TEST
		printf("Press Enter...\n");
		while (getchar() != '\n');
		#endif
	}	
}

void deleteData(t_Listenkopf *li)
{
	int i;

	for (i = 0; i < N; i++)
	{
		Assert(loeschenElement(li, testListe[i]) == 0, "Element nicht gefunden: Abbruch!!!");
		printListe(li);
		printf("Element %s gelöscht\n", testListe[i]);

		#ifdef TEST
		printf("Press Enter...\n");
		while (getchar() != '\n');
		#endif
	}
}

void testTeil3 (t_Listenkopf *li)
{
	printf("Testfall: einfuegen und loeschen\n");

	printf("Daten einfügen:\n");
	insertData(li);

	Assert(ListeIsSorted(li), "Liste ist nicht Sortiert");
	printf("Liste ist sortiert !\n\n");

	printf("%d\n", li->anzahlElemente);

	printf("Daten löschen:\n");
	deleteData(li);

	Assert((li->erstesElement == NULL && li->letztesElement == NULL && li->anzahlElemente == 0), "Liste wurde nicht gelöscht");
	printf("Liste ist erfolgreich gelöscht worden !\n\n");

	#ifdef TEST
	printf("Press Enter...\n");
	while (getchar() != '\n');
	#endif
}

int main ()
{
	t_Listenkopf liste;

	GenTestdaten();
	initListe(&liste);
	printf("Testtreiber beginnt mit leerer Liste:\n");
	printListe(&liste);      
	testTeil3(&liste);      
	printf("Testtreiber erfolgreich beendet.");
	return (0);
}
