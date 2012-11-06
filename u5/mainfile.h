#ifndef _MAINFILE_H_
#define _MAINFILE_H_

/* Struct */
struct Fraction_s
{
	int num;		/* numerator */
	int deno;		/* denominator */
};

/* Prototypen der benötigten Funktionen */
struct Fraction_s pro (struct Fraction_s, struct Fraction_s);
struct Fraction_s sum (struct Fraction_s, struct Fraction_s);
struct Fraction_s quo (struct Fraction_s, struct Fraction_s);
struct Fraction_s dif (struct Fraction_s, struct Fraction_s);

int gcd (int, int);

struct Fraction_s reduce (struct Fraction_s);

#endif
