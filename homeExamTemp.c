#include <stdio.h>
#include "header.h"
#include <stdlib.h>

int main (int argc, char *argv[])
{
	FILE* f = fopen(argv[1], "r");
	int i = 0;
	long count = 0;
	long *countPtr = malloc(sizeof(long);
	countPtr = &count;
	fscanf(f, "%d", &i);
	int numbers[2000000];

	while(!feof (f))
	{
		fscanf(f, "%d", &numbers[*countPtr]);
	       	*countPtr += 1;
	}
	fclose(f);
	
	printf("Numbers unsorted:\n");
	for(int j = 0; j < *countPtr; j++)
	{
		printf("%d, ", numbers[j]);
	}

	printf("Number of entries in %s: %d\n",argv[1], *countPtr);

	Sort(numbers, countPtr);

	printf("sorted list:\n");
	for(int k = 0; k < *countPtr; k++)
	{
		printf("%d, ", numbers[k]);
	}
	free(countPtr);
	return 0;
}

void Sort(int nmbrToSort[], long *arraySize)
{
	int i, j, tempNmbr;
	for(int i = 0; i < (*arraySize - 1); i++)
	{
		for(j = 0; j < (*arraySize - 1); j++)
		{
			if(nmbrToSort[j] > nmbrToSort[j + 1])
			{
				tempNmbr = nmbrToSort[j + 1];
				nmbrToSort[j + 1] = nmbrToSort[j];
				nmbrToSort[j] = tempNmbr;
			}
		}
	}
}
