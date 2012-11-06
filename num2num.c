#include <stdio.h>

int num2num (unsigned long long, int);

int main(void)
{
	long long number;
	int base;

	printf("Please type a number: ");
	
	scanf("%llu", &number);

	do
	{
		if (!base || base > 16 || base < 2)
			printf("Convert to base (2-16): ");

		scanf("%d", &base);
	}
	while (base > 16 || base < 2);
	

	printf("Result: ");

	num2num(number, base);
}

int num2num (unsigned long long n, int b)
{	
	char str[255];
	int rmd[255], i = 0, j = 0;	

	while (n > 0)
	{
		rmd[i++] = n % b;
		n = n / b;
	}

	while (i > 0)
	{
		i--;

		if (rmd[i] == 10)
			str[j] = 'A';
		else if (rmd[i] == 11)
			str[j] = 'B';
		else if (rmd[i] == 12)
			str[j] = 'C';
		else if (rmd[i] == 13)
			str[j] = 'D';
		else if (rmd[i] == 14)
			str[j] = 'E';
		else if (rmd[i] == 15)
			str[j] = 'F';
		else
			str[j] = 48 + rmd[i];

		j++;
	}

	str[j] = '\0';

	printf("%s\n", str);

	return 0;
}
