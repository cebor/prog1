#ifndef _POLY_H_
#define _POLY_H_


typedef enum
{
	CL_NOERROR,			/* Parameter sind gültig */
	CL_EMINOUTOFRANGE,	/* emin ist kleiner/gleich 2 */
	CL_EMAXOUTOFRANGE,	/* emax ist kleiner als emin */
	CL_RADIUSINVALID,	/* Radius ist kleiner/gleich 0.0 */
	CL_PARAMMISSING,	/* einer der Parameter emin/emax/r fehlt */
	CL_UNKOWNPARAM		/* ein nicht definierter String wurde in der Kommandozeile verwendet */
} cl_errors_t;

typedef enum
{
	FALSE,
	TRUE
} boolean_t;

typedef struct
{
	int min;
	int max;
	double radius;
} mainParameters_t;

typedef struct
{
	int corners;
	double area;
	double side;
	double variance;
} polygon_t;

/* Prototypen der benötigten Funktionen */
void strich (int n, char c); /* gibt n mal das Zeichen c aus  */

void calcPolygons(polygon_t data[], mainParameters_t params);
void outputPolygons(polygon_t data[], int n_Lines);

#endif
