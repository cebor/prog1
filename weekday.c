#include <stdio.h>

#define LEN 11

typedef struct
{
	int d;
	int m;
	int y;
} date_t;

date_t getDate (void);

int main(int argc, char const *argv[])
{
	date_t date;
	
	date = getDate();

	printf("%d/%d/%d\n", date.d, date.m, date.y);

	return 0;
}

date_t getDate (void)
{
	date_t date;
	char string[LEN];

	printf("Please give me a Date:\n");

	fgets(string, LEN, stdin);

	string[2] = string[5] = string[10] = '\0';

	date.d = atoi(&string[0]);
	date.m = atoi(&string[3]);
	date.y = atoi(&string[6]);

	return date;
}
