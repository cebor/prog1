#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <string.h>
#include <stdlib.h>

void line (int n, char c);
void printAsciiFreq (char *text[], const int n);

void printText(char *text[], const int n);
// gibt einen Text ((Feld von Zeichenketten) mit n Worten aus
void textReverse(char *text[], const int n);
// Invertiert in einem Text (Feld von Zeichenketten) die Reihenfolge
// der Wörter; die Invertierung erfolgt ausschließlich durch Vertauschung
// von Zeigern, nicht durch umkopieren der Wörter!
void deleteText(char *text[], const int n);
// gibt den Speicherplatz für die Wörter des Textes wieder frei


int main (int argc, char *argv[]) 
{
	char **feld;
	feld = malloc(argc * sizeof(char *) + 1);

	feld[0] = argv[0];
	feld[1] = argv[1];
	feld[2] = argv[2];
	feld[3] = argv[3];

	printf("%s\n", feld[3]);

	free(feld);

	line(23, '-');
	printf("Statistik Kommandozeile\n");
	line(23, '-');

	printf("Anzahl der Buchstaben der Parameter:\n");
	printAsciiFreq(argv, argc);

	printf("\n");
	printf("Aufgabe: 2\n");

	printText(argv, argc);

	return 0;
}

void line (int n, char c) 					// gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}

void printAsciiFreq (char *text[], const int n)
{
	int i;
	int chars[256] = { 0 };  // ascii tabell mit nullen vorinitialisieren

	// schleife: argumente
	for (i = 1; i < n; i++)
	{
		int j;
		// schleife: geht den string durch
		for (j = 0; text[i][j] != 0; j++)
			chars[text[i][j]] += 1;		// zählt die häufigkeit beim einzelen ascii wert hoch
	}

	// ausgabe der häufigkeit
	for (i = 0; i < 256; i++)
		if (chars[i] != 0)
		{
			printf("%c: ", i);
			printf("%d ", chars[i]);
		}

	printf("\n");
}

void printText(char *text[], const int n)
{
	int i;
	for (i = 1; i < n; i++)
		printf("%s ", text[i]);
	printf("\n");
}
