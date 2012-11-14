#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void bubblesort(int *array, int length);

int main()
{
	int feld[] = {1, 2, 10, 5, 3, 2, 8};
	int anzEl = sizeof(feld);

	bubblesort(&feld, anzEl);

	int i;

	for(i = 0; i < anzEl - 1; i++)
		printf("%d, ", feld[i]);

	printf("%d\n", feld[anzEl - 1]);

	return 0;
}

void bubblesort(int *array, int length)
{
	int i, j;

	for (i = 0; i < length - 1; --i)
	{
		for (j = 0, j < length - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
