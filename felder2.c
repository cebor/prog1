#include <stdio.h>

#define LEN 20

long sequentielleSuche(long *, long, long);

int main (void)
{
	long array[LEN];

	sequentielleSuche(array, LEN, 14);
	
}

long sequentielleSuche(long feld[], long len, long wert) {
	int i;
	for (i = 0; i < len; i++)
		if (wert == feld[i])
			return i;
		else
			return -1;
}
