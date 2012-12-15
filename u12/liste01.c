//*********************************************************************
// Source File : liste01.c
// ADT f�r Verwaltung einer einfach verketteten Liste
// Verfasser   : R.Feindor / R.H�ttl
// Datum       : 18.02.2008
// �nderungen  : 21.12.2010 J. Schmidt
//*********************************************************************
#include "liste01.h"

// gibt die Liste li am Bildschirm aus
void printListe(const t_Listenkopf *li)
{
}

// erzeugt ein neues Element und haengt es hinten an
void pushBack(t_Listenkopf *li, const char *s)
{
}

// gibt das erste Element zur�ck und entfernt es aus li
void popFront(t_Listenkopf *li, char *s)
{
}

// besetzt li vor (NULL-Pointer, anzahlZeilen=0 )
void initListe (t_Listenkopf *li)
{
   li->erstesElement = NULL;
   li->letztesElement = NULL;
   li->anzahlElemente = 0;
}

// erzeugt ein neues Element und fuegt es vorne ein
void pushFront(t_Listenkopf *li, const char *s)
{
   t_element *p;                                     // pointer
   p = (t_element*) malloc(sizeof(t_element));       // Speicher anfordern
   Assert(p != NULL, "kein Speicher bei malloc");     // pr�fen 
   strcpy (p->inhalt, s);                            // Element f�llen
   p->next = NULL;

   // vorn einf�gen:
   p->next = li->erstesElement;
   li->erstesElement = p;

   if (li->letztesElement == NULL) // wenn Liste bisher leer, sonst bleibt das letzte Element
      li->letztesElement = p;

   li->anzahlElemente++;
 }

