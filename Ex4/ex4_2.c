/******************************************
* Matan Ben Moshe
* 208583070
* 83-120-04
* ex4_2.c
******************************************/

//Header file.
#include "ex4.h"
//Standard library.
#include <stdio.h>

//Decletarion.
int FindMaxSet(int arr[], int size, int i, int finelmax, int count);

/*********************************************************************************************
Function name: MaxSet
Input: int array and its size.
Output: none
The function operation: Calls FindMaxSet and prints the length of the longest increasing sequence in the array.
**********************************************************************************************/
void MaxSet(int arr[], int size)
{
	int maxSet;
	maxSet = FindMaxSet(arr, size, 0, 0, 0);
	printf("%d\n", maxSet);

}

/*********************************************************************************************
Function name: FindMaxSet
Input: int array and its size. (plus initializations for the index, largest number and length count.)
Output:length of longest increasing sequence.
The function operation: Goes to the end of the array, and then returns to previous index each time checking all possible sequences from this point on and returning 
						the length of the longest sequence. 
**********************************************************************************************/
int FindMaxSet(int arr[], int size, int i, int biggerThan, int count)
{
	int length1, length2;
	// Stop condition.
	if (i == size) 
		return count;
	// Go to the end of the array.
	length1 = FindMaxSet(arr, size, i + 1, biggerThan, count);
	// If current number is bigger than the biggest number yet -->
	if (arr[i] > biggerThan)
	{
		// -->Go foward and add to count
		length2 = FindMaxSet(arr, size, i + 1, arr[i], count + 1);
		// If length count is longer than the stored one, replace it.
		if (length2 > length1)
			length1 = length2;
	}

	return length1;
}