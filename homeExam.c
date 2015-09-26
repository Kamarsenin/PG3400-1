#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	const int LENGTH_MAX = 2000000, INPUT_MAX = 10;
	
	FILE* f = fopen(argv[1], "r");
	int count = 0, i = 0;

	fscanf(f, "%d", &i);
	int *numbers = malloc(LENGTH_MAX * sizeof(int));

	while(!feof (f))
	{
		fscanf(f, "%d", &numbers[count]);
	       	count++;
	}
	fclose(f);
	
	printf("Numbers unsorted:\n");
	for(int j = 0; j < count; j++)
	{
		printf("%d, ", numbers[j]);
	}

	printf("Number of entries in %s: %d\n",argv[1], count);

	int *unsortedNumbers = malloc(count * sizeof(int));
	memcpy(unsortedNumbers, numbers, count * sizeof(int));

	Sort(numbers, count);

	printf("sorted list:\n");
	for(int k = 0; k < count; k++)
	{
		printf("%d, ", numbers[k]);
	}
	
	Search(numbers, unsortedNumbers, count);
	free(unsortedNumbers);
	free(numbers);
	return 0;
}

int Search(int nmbrList[], int unsortedNmbrList[], int arraySize)
{
	char *end;
	char buf[10];
	int searchInput;
	bool numberFound = false;
	printf("\n\nEnter number you want to search for: ");

	if(fgets(buf, sizeof(buf), stdin))
	{
		if(1 == sscanf(buf, "%d", &searchInput))
		{
			if(searchInput == 0)
			{
				printf("%d entered, shutting down", searchInput);
				return 0;
			}

			for(int i = 0; i < arraySize - 1; i++)
			{
				if(nmbrList[i] == searchInput)
				{
					printf("%d is found at position %d in the sorted list\n",					  		   searchInput, i);
					numberFound = true;
					
				}
				if(unsortedNmbrList[i] == searchInput)
				{
					printf("%d is found at position %d in the unsorted list\n",
					searchInput, i);
				}
			}
			if(numberFound == false)
				printf("%d not found\n", searchInput);
		}
	}
	return 0;
}
void Sort(int nmbrToSort[], int arraySize)
{
	int i, j, tempNmbr;
	for(int i = 0; i < (arraySize - 1); i++)
	{
		for(j = 0; j < (arraySize - 1); j++)
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
