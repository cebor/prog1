//*******************************************************************
// include-file: inf1.h                                              
// alles Allgemeine f�r �bungen im Semester inf1                     
// Verfasser   : Feindor / Schmidt                                      
// Datum       : Urprogramm: 1.10.1996                                           
// letzte �nderungen: 5.11.2010
//*******************************************************************
#ifndef INF1_H
#define INF1_H

// Einbinden von n�tigen Header-Dateien                              
#include <stdio.h>  // Standard Input/ Output  z.B. scanf, printf 
#include <stdlib.h>  // f�r Standard-Utility-Funktionen wie exit() oder rand() 
#include <conio.h>

// Standarddeklarationen 
typedef unsigned char byte;
typedef enum {false=0, true=1} bool;   // in C99 schon vorhanden

// Deklaration von Prototypen, die in gesonderten Moduln (z.B.inf1.c)
// bereitgestellt werden. Diese Moduln m�ssen daher dazugelinkt werden 
void strich (int n, char c);      // gibt n mal das Zeichen c aus 
void dialog(char *ueberschrift);  // gibt �berschrift aus

// die folgenden Funktionen kommen sp�ter dazu 
void Assert (bool ok, char *meldung);// gibt Fehlermeldung, wenn nicht ok 


#endif

