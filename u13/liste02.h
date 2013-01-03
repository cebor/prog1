//*********************************************************************
// Header File : liste02.h
// ADT für Verwaltung einer einfach verketteten Liste
// Verfasser   : R.Feindor / R.Hüttl
// Datum       : 18.02.2008
// Änderungen  : 11.1.2011 J. Schmidt
//*********************************************************************

#ifndef LISTE02_H
#define LISTE02_H

#include "inf1.h"
#include <string.h>
#include <time.h>

#define LAENGE 80
#define NULLSTRING ""

typedef struct t_element
{ 
	char inhalt[LAENGE];       // Inhalt als String fester Länge 
	struct t_element *next;    // Zeiger auf den Nachfolger 
} t_element;

typedef struct  
{
	struct t_element *erstesElement;
	struct t_element *letztesElement;
	int anzahlElemente;
} t_Listenkopf;


// besetzt li vor (NULL-Pointer, anzahlZeilen=0 )
void initListe (t_Listenkopf *li);

// erzeugt ein neues Element und fuegt es vorne ein
void pushFront(t_Listenkopf *li, const char *s);

// gibt die Liste li am Bildschirm aus
void printListe(const t_Listenkopf *li);

// erzeugt ein neues Element und haengt es hinten an
void pushBack(t_Listenkopf *li, const char *s);

// gibt das erste Element zurück und entfernt es aus li
void popFront(t_Listenkopf *li, char *s);


// ab hier Version 2                         *************************** V2 

// erzeugt ein neues Element und fügt es sortiert in li ein
void einfuegenElement(t_Listenkopf *li, const char *s);

// löscht das erste auftretende Element mit dem Inhalt s
// returncode = 0 bei geloescht, 1 falls nicht gefunden
int loeschenElement(t_Listenkopf *li, const char *s);

// true, wenn die Elemente von li sortiert sind
bool ListeIsSorted (const t_Listenkopf *li);

#endif // LISTE02_H
