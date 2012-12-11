#include <stdio.h>
#include <stdlib.h>

void usage(void)
{
	printf("Usage:\n");
	printf(" -f<name>\n");
	printf(" -d<name>\n");
	exit (8);
}

int main(int argc, char *argv[])
{
	printf("Program name: %s\n", argv[0]);

	while ((argc > 1) && (argv[1][0] == '-'))
	{
		switch (argv[1][1])
		{
			case 'f':
				printf("%s\n",&argv[1][2]);
				break;

			case 'd':
				printf("%s\n",&argv[1][2]);
				printf("%s\n",&argv[1][2]);
				break;

			default:
				printf("Wrong Argument: %s\n", argv[1]);
				usage();
		}

		++argv;
		--argc;
	}
	return (0);
}