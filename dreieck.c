#include <stdio.h>

void viereck (int, int, int *flaeche, int *umfang);

int main () 
{
	int a, b;

	viereck(6,7, &a, &b);

	printf("%d %d\n", a, b);

	return 0;
}


void viereck (int x, int y, int *flaeche, int *umfang)
{
	*flaeche = x * y;
	*umfang = (x + y) * 2;
}