#include "funcs.h"
#include "arbeitszeit.h"
#include <stdio.h>

unsigned int menu (void)
{
	int ch = 0;

	printf("Bitte waehlen Sie:\n");
	printf("1 - Liste der Arbeitszeiten\n");
	printf("2 - Liste der Mitarbeiter\n");
	printf("3 - Gesamtarbeitszeit\n");
	printf("0 - End\n");

	scanf("%d", &ch);

	return ch;
}

void listAz () {
	FILE *az_f;

	t_arbeitszeit az;

	int i = 1;

	az_f = fopen("assets/arbeitszeit.dat", "rb");

	if(az_f == NULL)
		fprintf(stderr, "Fehler beim Öffnen der Datei!\n");

	fread(&az, sizeof(t_arbeitszeit), 1, az_f);
	while (!feof(az_f))
	{
		printf("%d %s %.1f\n", az.id, az.date, az.h);
		fread(&az, sizeof(t_arbeitszeit), 1, az_f);
	}

	fclose(az_f);

	printf("\n");
}

void listMA () {
	FILE *ma_f;

	t_mitarbeiter ma;

	int i = 1;

	ma_f = fopen("assets/mitarbeiter.dat", "rb");

	if(ma_f == NULL)
		fprintf(stderr, "Fehler beim Öffnen der Datei!\n");

	fread(&ma, sizeof(t_mitarbeiter), 1, ma_f);
	while (!feof(ma_f))
	{
		printf("%d %s\n", ma.id, ma.name);
		fread(&ma, sizeof(t_mitarbeiter), 1, ma_f);
	}

	fclose(ma_f);

	printf("\n");
}
