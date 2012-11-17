#include <stdio.h>

#define NAME_LEN 25
#define COUNTRY_LEN 5
#define TOWNS_LEN 20

struct Town_s {
	char name[NAME_LEN];
	char country[COUNTRY_LEN];
	int id;
};

void output(const struct Town_s *towns);

int main()
{
	struct Town_s towns[TOWNS_LEN] = 
	{
		{"Wien", "A", 1700000},
		{"Graz", "A", 1700000},
		{"Berlin", "D", 1700000},
		{"Zuerich", "CH", 1700000},
		{"Koppenhagen", "DK", 1700000}
	};

	output(&towns[2]);  //Hier wird nur ein einziges übergeben: bzw die startaddress des element 2
}

void output(const struct Town_s *towns) {
	printf("%s %s %d\n", towns->name, towns->country, towns->id);  // pointer aud die einzl elemente!
}