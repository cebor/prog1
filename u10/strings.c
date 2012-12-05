#include <stdio.h>  /* Standard Input/Output  z.B. scanf, printf */
#include <string.h>
#include <stdlib.h>

#define ASCII 256

void line (int n, char c);
void printAsciiFreq (char *text[], const int n);

void stats (int argc, char *argv[]);
void reverse (int argc, char *argv[]);

void printText (char *text[], const int n);
void textReverse (char *text[], const int n);
void deleteText (char *text[], const int n);


int main (int argc, char *argv[]) 
{
	// Aufgabe 1
	stats(argc, argv);

	// Aufgabe 2
	reverse(argc, argv);

	return 0;
}

void line (int n, char c) 					// gibt n mal das Zeichen c aus
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%c", c);
	printf("\n");
}


void stats (int argc, char *argv[])
{
	line(23, '-');
	printf("Statistik Kommandozeile\n");
	line(23, '-');

	printf("\n");

	printText(argv, argc);

	printf("\n");

	printf("Anzahl der Buchstaben der Parameter:\n");
	printAsciiFreq(argv, argc);

	printf("\n");
	printf("\n");
}

void reverse (int argc, char *argv[])
{
	int i;
	char **array;
	// speicher allozierung: pointers auf strings
	array = malloc((argc-1) * sizeof(char *));	// anzahl der argumente
	if (array == NULL) exit(0);

	// speicher allozierung: der einzelnen strings
	for (i = 1; i < argc; i++)
	{
		// länge des arguments
		size_t ln = strlen(argv[i]);

		// länge im array allozieren
		array[i-1] = malloc((ln + 1) * sizeof(char));
		if (array[i-1] == NULL) exit(0);

		// argument ins array kopieren
		strcpy(array[i-1], argv[i]);
	}

	line(23, '-');
	printf("Aufgabe 2\n");
	line(23, '-');

	printText(array, argc - 1);

	textReverse(array, argc -1);

	printText(array, argc - 1);

	deleteText(array, argc - 1);

	free(array);
}

void printAsciiFreq (char *text[], const int n)
{
	int i;
	int chars[ASCII] = { 0 };  // ascii tabell mit nullen vorinitialisieren

	// schleife: argumente
	for (i = 1; i < n; i++)
	{
		int j;
		// schleife: geht den string durch
		for (j = 0; text[i][j] != 0; j++)
			chars[text[i][j]] += 1;		// zählt die häufigkeit beim einzelen ascii wert hoch
	}

	// ausgabe der häufigkeit
	for (i = 0; i < ASCII; i++)
		if (chars[i] != 0)
		{
			printf("%c: ", i);
			printf("%d ", chars[i]);
		}

	printf("\n");
}

void printText (char *text[], const int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s ", text[i]);
	printf("\n");
}

void textReverse (char *text[], const int n)
{
	int i, j;
	char *tmp;

	for (i = 0, j = n - 1; i < n / 2; i++, j--)
	{
		tmp = text[i];
		text[i] = text[j];
		text[j] = tmp;
	}
}

void deleteText (char *text[], const int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(text[i]);
}
