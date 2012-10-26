//*******************************************************************
// Programm    : BENZIN                                                            
// Verfasser   : Feindor/Schmidt
// �bungsbeispiel f�r:
//               Programmaufbau, Typen, Konstanten, Variablen,
//               Bildschirm-Ein-/Ausgabe, Wertzuweisung, if              
// Datum       : Urprogramm: 1.10.1996
// Eingabe     : Kilometerzahl, Benzinverbrauch  in Liter               
// Verarbeitung: Berechnung des Durchschnittsverbrauchs          
// Ausgabe     : Verbrauch                                                         
// �nderungen  : 23.09.2012
//*******************************************************************

// Einbinden von n�tigen Header-Dateien                                     
#include <stdio.h>  // Standard Input/ Output  z.B. scanf, printf
#include <stdlib.h> // Standard-Bibliothek, z.B. f�r system

#define STRINGLAENGE 20


// Definition der Fahrzeugdatenstruktur
struct s_AutoDaten
{
	float km;		// gefahrene km
	float liter;	// verbrauchter Sprit (gesamt)
};

/* Deklaration der Funktionen */

void eingabeName(char name[]);
struct s_AutoDaten datenEingabe(void);
float verarbeitung(const struct s_AutoDaten daten);
void ausgabe(const float verbrauch, const char name[]);


int main(void) // Beginn Hauptprogramm          **************************
{
	//************************ Vereinbarungsteil **************************
	struct s_AutoDaten fzg_Daten;
	float verbrauch;
	char  name[STRINGLAENGE];


	//************************ Anweisungsteil  ****************************
	// Dialoger�ffnung 

	printf ("BENZIN: Programm zum Kennenlernen\n");
	printf ("---------------------------------\n");

	// Daten einlesen   
	eingabeName(name);

	printf ("Als Beispiel berechne ich Dir den\n" \
		"Benzinverbrauch Deines Autos.\n");

	fzg_Daten = datenEingabe();
	
	// Daten verarbeiten
	verbrauch = verarbeitung(fzg_Daten);

	// Ergebnis ausgeben
	ausgabe(verbrauch, name);

	// und Ende
	printf("Servus! \n");

	// system("pause");

	return(0);
} //***************** Ende Hauptprogramm *****************************


/* Definiton der Funktionen */

// Einlesen des Benutzernamens
void eingabeName(char name[])
{
	printf ("Hallo, wir wollen etwas C lernen.\nWie heisst Du? ");
	scanf  ("%s", name);
	printf ("Freut mich, %s, Dich kennenzulernen!! \n\n", name);
}

// Einlesen der Fahrzeugdaten
struct s_AutoDaten datenEingabe(void)
{
	struct s_AutoDaten daten;

	printf ("Bitte gib ein: \nGefahrene Kilometer: ");
	scanf ("%f", &(daten.km));
	printf ("Benzinmenge in Liter: ");
	scanf ("%f", &(daten.liter));

	return daten;
}

// Berechne Spritverbrauch auf 100km
float verarbeitung(const struct s_AutoDaten daten)
{
	float verbrauch;
	//int verbrauch;

	verbrauch = daten.liter /  daten.km;

	return verbrauch;
}

// Ausgabe des Verbrauchs und Test auf Plausibilit�t
void ausgabe(const float verbrauch, const char name[])
{
	const float untergrenze = 0.03, obergrenze = 0.1;

	printf ("Benzinverbrauch: %10.2f Liter pro km\n", verbrauch);

	if (obergrenze < verbrauch)
		printf ("%s, %s! Das ist Energieverschwendung!!!\n", name, name);

	if (verbrauch < untergrenze)
		printf ("%s, %s! Ich glaube, Du schwindelst!!!\n", name, name);
}
