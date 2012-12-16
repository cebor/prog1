//*********************************************************************
// Source File : liste01.c
// ADT für Verwaltung einer einfach verketteten Liste
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 21.12.2010 J. Schmidt
//*********************************************************************
#include "liste01.h"

// gibt die Liste li am Bildschirm aus
void printListe (const t_Listenkopf *li)
{
	t_element *p = li->erstesElement;

	while (p != NULL)
	{
		printf("%s\n", p->inhalt);
		p = p->next;
	}
}

// erzeugt ein neues Element und haengt es hinten an
void pushBack (t_Listenkopf *li, const char *s)
{
	t_element *p, *q;								// pointer
	p = (t_element*) malloc(sizeof(t_element));		// Speicher anfordern
	Assert(p != NULL, "kein Speicher bei malloc");	// prüfen
	strcpy(p->inhalt, s);							// Element füllen
	p->next = NULL;

	// hinten einfügen
	// Liste ist Leer
	if (li->letztesElement == NULL)
	{
		li->letztesElement = p;
		li->erstesElement  = p;
	}
	// Liste enthält genau ein Element
	else if (li->letztesElement == li->erstesElement)
	{
		q = li->erstesElement;
		q->next = p;
		li->letztesElement = p;
	}
	// Liste enthält mehr als ein Element
	else
	{
		q = li->letztesElement;
		q->next = p;
		li->letztesElement = p;
	}
	li->anzahlElemente++;
}

// gibt das erste Element zurück und entfernt es aus li
void popFront (t_Listenkopf *li, char *s)
{
	t_element *p;

	// Liste muss min ein Element enthalten
	if(li->erstesElement != NULL)
	{
		p = li->erstesElement;

		// Element zurückgeben
		strcpy(s, p->inhalt);

		// Liste enthält mehr als ein Element
		if (li->erstesElement != li->letztesElement)
			li->erstesElement = p->next;
		// Liste Enthält genau ein Element
		else
			li->erstesElement = li->letztesElement = NULL;

		li->anzahlElemente--;
	}
}

// besetzt li vor (NULL-Pointer, anzahlZeilen=0 )
void initListe (t_Listenkopf *li)
{
	li->erstesElement = NULL;
	li->letztesElement = NULL;
	li->anzahlElemente = 0;
}

// erzeugt ein neues Element und fuegt es vorne ein
void pushFront (t_Listenkopf *li, const char *s)
{
	t_element *p;									// pointer
	p = (t_element*) malloc(sizeof(t_element));		// Speicher anfordern
	Assert(p != NULL, "kein Speicher bei malloc");	// prüfen
	strcpy(p->inhalt, s);							// Element füllen
	p->next = NULL;

	// vorn einfügen:
	p->next = li->erstesElement;
	li->erstesElement = p;

	if (li->letztesElement == NULL) // wenn Liste bisher leer, sonst bleibt das letzte Element
	  li->letztesElement = p;

	li->anzahlElemente++;
}
