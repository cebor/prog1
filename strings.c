#include <stdio.h>
#include <string.h>

#define L1 50
#define L2 50
#define L3 L1+L2-1

int main (void)
{
	char vorname[L1]  = "felix";
	char nachname[L2] = "itzenplitz";
	char name[L3];

	strcpy(name, vorname);
	strcat(name, " ");
	strcat(name, nachname);

	printf("%s\n", name);
}