#include <stdio.h>

unsigned sum (unsigned);

int main(int argc, char const *argv[])
{
	

	printf("%d\n", sum (3));


	return 0;
}


unsigned sum (unsigned n)
{
	int erg;

	if (n <= 1)
		return n;

	erg = sum(n-1) + n;

	return erg;
}