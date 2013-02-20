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

void listAz (void)
{
	FILE *az_f;

	t_arbeitszeit az;

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

void listMA (void)
{
	FILE *ma_f;

	t_mitarbeiter ma;

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

void listAll (void)
{
	FILE  *az_f, *ma_f;

	t_arbeitszeit az;
	t_mitarbeiter ma;

	az_f = fopen("assets/arbeitszeit.dat", "rb");
	if(az_f == NULL)
		fprintf(stderr, "Fehler beim Öffnen der Datei!\n");

	ma_f = fopen("assets/mitarbeiter.dat", "rb");
	if(ma_f == NULL)
		fprintf(stderr, "Fehler beim Öffnen der Datei!\n");


	fread(&az, sizeof(t_arbeitszeit), 1, az_f);
	while (!feof(az_f))
	{
		fseek(ma_f, 0L, SEEK_SET);

		fread(&ma, sizeof(t_mitarbeiter), 1, ma_f);
		while (ma.id != az.id && !feof(ma_f))
		{
		  	fread(&ma, sizeof(t_mitarbeiter), 1, ma_f);
		}

		printf("%3d   %s    %s   %5.1f\n", az.id, ma.name, az.date, az.h);
		fread(&az, sizeof(t_arbeitszeit), 1, az_f);
	}
	
	fclose(ma_f);
	fclose(az_f);

	printf("\n");
}
