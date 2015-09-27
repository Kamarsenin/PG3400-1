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

	printf("Number of entries in %s: %d\n",argv[1], count);

	int *unsortedNumbers = malloc(count * sizeof(int));
	memcpy(unsortedNumbers, numbers, count * sizeof(int));

	char buf[INPUT_MAX];
	int searchInput;
	printf("Enter the number you wish to search for: ");
	if(fgets(buf, sizeof(buf), stdin))
	{
		if(1 == sscanf(buf, "%d", &searchInput))
		{
			if(searchInput == 0)
			{
				printf("%d entered, shutting down", searchInput);
				exit(0);
			}
		}

	}

	bubbleSort(numbers, count);
	
	linearSearch(searchInput, unsortedNumbers, count);
	binarySearch(searchInput, numbers, count);

	freeAllocs(unsortedNumbers, numbers);
	return 0;
}

int freeAllocs(int unsortedList[], int sortedList[])
{
	free(unsortedList);
	free(sortedList);

	return 0;
}
int binarySearch(int searchInput, int sortedList[], int arraySize)
{
	int first = 1,
	    last = arraySize - 1,
	    middle = (first + last) / 2;

	while(first <= last)
	{
		if(sortedList[middle] < searchInput)
			first = middle +1;
		else if(sortedList[middle] == searchInput)
		{
			printf("%d found at location %d in the sorted list\n", searchInput, middle + 1);
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}

	if(first > last)
		printf("%d not found\n", searchInput);

	return 0;
}

int linearSearch(int searchInput, int unsortedNmbrList[], int arraySize)
{
	bool numberFound = false;
	

	for(int i = 0; i < arraySize - 1; i++)
	{
		if(unsortedNmbrList[i] == searchInput && numberFound != true)
		{
			printf("%d is found at position %d in the unsorted list\n",
			searchInput, i);
			numberFound = true;
		}
	}
		if(numberFound == false)
			printf("%d not found\n", searchInput);

	return 0;
}
void bubbleSort(int nmbrToSort[], int arraySize)
{
	int tempNmbr;
	for(int i = 0; i < (arraySize - 1); i++)
	{
		for(int j = 0; j < (arraySize - 1); j++)
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
