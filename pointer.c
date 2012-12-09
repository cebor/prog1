#include <stdio.h>
#include <stdlib.h>

void bla(int *ag);

int main(int argc, char const *argv[])
{
	int ac = 5;

	bla(&ac);

	printf("%d\n", ac);


	return 0;
}

void bla(int *ag)
{
	*ag += 1;

	printf("%d\n", *ag);
}
