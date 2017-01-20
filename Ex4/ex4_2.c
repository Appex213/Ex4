#include "ex4.h"
#include <stdio.h>

int longestSet(int arr[], int size, int i, int finelmax, int count);

void MaxSet(int arr[], int size)
{
	int i = 0, biggerThan = 0, count = 0, maxSet;
	maxSet = longestSet(arr, size, i, biggerThan, count);
	printf("%d\n", maxSet);

}

int longestSet(int arr[], int size, int i, int biggerThan, int count)
{
	int length1, length2;
	if (i == size) 
		return count;

	length1 = longestSet(arr, size, i + 1, biggerThan, count);
	if (arr[i] > biggerThan)
	{
		length2 = longestSet(arr, size, i + 1, arr[i], count + 1);
		if (length2 > length1)
			length1 = length2;
	}

	return length1;
}