#include "funcs.h"
#include "arbeitszeit.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int m;
	
	while (m = menu())
		switch(m)
		{
			case 1:
				system("clear");
				listAz();
				break;
			case 2:
				system("clear");
				listMA();
				break;
			default:
				system("clear");
				exit(0);
		}

}
