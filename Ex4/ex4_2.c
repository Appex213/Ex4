#include "ex4.h"
#include <stdio.h>

int FindMaxSet(int arr[], int size, int i, int finelmax, int count);

void MaxSet(int arr[], int size)
{
	int maxSet;
	maxSet = FindMaxSet(arr, size, 0, 0, 0);
	printf("%d\n", maxSet);

}

int FindMaxSet(int arr[], int size, int i, int biggerThan, int count)
{
	int length1, length2;
	if (i == size) 
		return count;

	length1 = FindMaxSet(arr, size, i + 1, biggerThan, count);
	if (arr[i] > biggerThan)
	{
		length2 = FindMaxSet(arr, size, i + 1, arr[i], count + 1);
		if (length2 > length1)
			length1 = length2;
	}

	return length1;
}