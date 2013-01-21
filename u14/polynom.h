//*******************************************************************
// include-file: polynom.h
// Header-Datei für Polynom
// Verfasser   : Feindor/Schmidt
// Datum       : Urprogramm 1.10.1996
// letzte Änderungen: 9.1.2013
// 
//*******************************************************************
#ifndef POLYNOM_H
#define POLYNOM_H

void EinlesenGrad (int *);
void EinlesenKoeff (int, int *);
void EinlesenArg (double *);
void EinlesenStartwert (double * start);

// Berechnung des Wertes des Polynoms a[0] + a[1] x + ... + a[n] x hoch n
double PolynomWert (const int n, const int a[], const double x);

// Berechnung des Wertes der 1. Ableitung des Polynoms an der Stelle x
double PolyAblWert (const int n, const int a[], const double x);

// Berechnung einer Nullstelle des Polynoms (n, a) aus Startwert s
// status 0: Nullstelle gefunden;1: waagrechte Tangente;2: keine Konvergenz
double Nullstelle (const int n, const int a[],const double s, int * status);

#endif
