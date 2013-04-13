#include <stdio.h>
#include <stdint.h>

#define LN 255

typedef struct mystruct_s
{
	int32_t i;
	float f;
	char str[LN];
} mystruct_t;

void itobin (int32_t);
void ftobin (float);
void strtobin (char *);

int main(int argc, char const *argv[])
{
	mystruct_t my;

	// Integer
	printf("Integer: ");
	scanf("%d", &my.i);

	itobin(my.i);

	// Float
	printf("Float: ");
	scanf("%f", &my.f);

	ftobin(my.f);

	// String
	printf("String: ");
	scanf("%s", my.str);

	strtobin(my.str);

	return 0;
}

void itobin (int32_t integer)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		printf("%c", (char) ((integer & (1 << i)) != 0) + '0');
	}

	printf("\n\n");
}

void ftobin (float f)
{
	union
	{
		int32_t i;
		float f;
	} uv;

	int i;
	
	uv.f = f;

	// w = *((int32_t *) &f); // ersetzt durch union

	for (i = 31; i >= 0; i--)
	{
		switch (i)
		{
			case 31:
				printf("Sign:\n");
				break;
			case 30:
				printf("Exponent:\n");
				break;
			case 22:
				printf("Significand:\n");
		}

		printf("%c", (char) ((uv.i & (1 << i)) != 0) + '0');

		switch (i)
		{
			case 31:
			case 23:
			case 0:
				printf("\n");
		}
	}

	printf("\n");
}

void strtobin (char *str)
{
	int i, j;

	i = 0;

	while (str[i] != 0)
	{
		printf("%c - %3d - 0x%x - ", str[i], (int)str[i], (int)str[i]);

		// Bin Umrechnung
		for (j = 7; j >= 0; j--)
		{
			printf("%c", ((str[i] & (1 << j)) != 0) + '0');
		}

		printf("\n");

		i++;
	}

	printf("\n");
}
