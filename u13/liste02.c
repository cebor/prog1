//*********************************************************************
// Source File : liste02_0.c Einfügemuster
// ADT für Verwaltung einer einfach verketteten Liste
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 11.1.2011 J. Schmidt
//*********************************************************************
#include "liste02.h"

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
	t_element *p;                                     // pointer
	p = (t_element*) malloc(sizeof(t_element));       // Speicher anfordern
	Assert(p != NULL, "kein Speicher bei malloc");     // prüfen 
	strcpy (p->inhalt, s);                            // Element füllen
	p->next = NULL;

	// vorn einfügen:
	p->next = li->erstesElement;
	li->erstesElement = p;
	if (li->letztesElement == NULL) // wenn Liste bisher leer, sonst bleibt das letzte Element
		li->letztesElement = p;

	li->anzahlElemente++;
}

// erzeugt ein neues Element und haengt es hinten an
void pushBack (t_Listenkopf *li, const char *s)
{
	t_element *p;                                     // pointer
	p = (t_element*) malloc(sizeof(t_element));       // Speicher anfordern
	Assert(p != NULL, "kein Speicher bei malloc");     // prüfen 
	strcpy (p->inhalt, s);                            // Element füllen
	p->next = NULL;

	// hinten anfügen:
	if (li->erstesElement == NULL)  // wenn Liste bisher leer
	{
		li->erstesElement = li->letztesElement = p;
	}
	else
	{
		li->letztesElement->next = p;
		li->letztesElement = p;
	}

	li->anzahlElemente++;
}

// gibt das erste Element zurück und entfernt es aus li
void popFront (t_Listenkopf *li, char *s)
{
	t_element *p;
	if (li->erstesElement == NULL)   // Liste ist leer
	{
		strcpy(s, NULLSTRING); // kein Speicher frei zu geben; nichts zu tun
		return; 
	}

	strcpy(s,  li->erstesElement->inhalt);   // Inhalt kopieren
	// erstes Element abbauen:
	p = li->erstesElement;
	li->erstesElement = p->next;
	free (p);
	li->anzahlElemente--;
	if (li->anzahlElemente == 0)
		li->letztesElement = NULL;

}

// gibt die Liste li am Bildschirm aus
void printListe (const t_Listenkopf *li)
{
	t_element *p;
	p= li->erstesElement;
	while (p != NULL)
	{
		printf("%s\n", p->inhalt);
		p = p->next;
	}
}


// ab hier Version 2                         *************************** V2

// erzeugt ein neues Element und fügt es sortiert in li ein
void einfuegenElement (t_Listenkopf *li, const char *s)
{
	t_element *p;                                     // pointer
	p = (t_element*) malloc(sizeof(t_element));       // Speicher anfordern
	Assert(p != NULL, "kein Speicher bei malloc");     // prüfen 
	strcpy (p->inhalt, s);                            // Element füllen
	p->next = NULL;

	if (li->erstesElement == NULL) // Liste bisher leer
	{
		li->erstesElement = li->letztesElement = p;
	}
	else if (strcmp (li->erstesElement->inhalt , p->inhalt) > 0)    // vorn einfügen
	{
		p->next = li->erstesElement;  
		li->erstesElement = p;
	}
	else                                        // echt einfügen
	{
		t_element *q = li->erstesElement;  // Hilfszeiger zum Durchwandern der Liste
		// solange noch ein Element kommt, dessen Inhalt < ist
		while ( (q->next != NULL) && (strcmp(q->next->inhalt, p->inhalt) < 0) )
			// Auswertung eines AND-Ausdrucks erfolgt von links
		{
		 q = q->next;         // weitergehen
		}

		// jetzt sind wir an der richtigen Stelle
		if (q->next == NULL)    // falls am Ende:
		 li->letztesElement = p;   

		p->next = q->next;  // Einketten
		q->next = p;
	}

	li->anzahlElemente++;
}

// löscht das erste auftretende Element mit dem Inhalt s
// returncode = 0 bei geloescht, 1 falls nicht gefunden
int loeschenElement (t_Listenkopf *li, const char *s)
{
	t_element *p, *prev;

	prev = NULL;

	// liste leer ?
	if (li->erstesElement == NULL)
		return 1;

	p = li->erstesElement;

	while (p != NULL)
	{
		// gefunden ?!
		if (strcmp(p->inhalt, s) == 0)
		{
			// element ist das erste
			if (p == li->erstesElement)
				li->erstesElement = p->next;
			// next vom vorherigen element auf nächstes setzten
			else
				prev->next = p->next;

			// element ist das letzte
			if (p == li->letztesElement)
				li->letztesElement = prev;

			// element löschen
			free(p);

			// anzahl reduzieren
			li->anzahlElemente--;

			return 0;
		}

		// vorheriges Element
		prev = p;
		// aktuelles Element
		p = p->next;
	}
	// nicht gefunden
	return 1;
}

// true, wenn die Elemente von li sortiert sind
bool ListeIsSorted (const t_Listenkopf *li)
{
	t_element *p;

	p = li->erstesElement;

	// liste leer ?!
	if (p == NULL)
		return true;

	while (p->next != NULL)
	{
		// ist aktuelles element kleiner als nächstes ?
		if (strcmp(p->inhalt, p->next->inhalt) > 0)
		{
			return false;
		}

		p = p->next;
	}

	return true;
}
