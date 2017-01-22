/******************************************
* Matan Ben Moshe
* 208583070
* 83-120-04
* ex4_3.c
******************************************/

//Header file.
#include "ex4.h"
//Standard library.
#include <stdio.h>

//Decletarion.
int CompareStrings(char s1[], char s2[], int i, int j, int count);

/*********************************************************************************************
Function name: DiffersInNChars
Input: Two strings to cpmpare and exact # of mismatches.
Output: None
The function operation: Calls CompareStrings and prints yes or no accordingly.
**********************************************************************************************/
void DiffersInNChars(char s1[], char s2[], int n)
{
	if (CompareStrings(s1, s2, 0, 0, 0) == n)
		printf("yes\n");
	else
		printf("no\n");
	
}

/*********************************************************************************************
Function name: CompareStrings
Input: Two strings to compare, Two initial indexes and initial mismatch count.
Output: # of mismaches.
The function operation: Compares every char pair in the same position in both strings, incrementing count when theres a mismatch or if
						the end of a string is reached (while the other one is still going).
**********************************************************************************************/
int CompareStrings(char s1[], char s2[], int i, int j, int count)
{
	// Stop condition - go back when reached the end of both strings.
	if (s1[i] == NULL && s2[j] == NULL)
		return 0;
	// Add to mismatch count when one string is shorter.
	else if (s1[i] == NULL)
		count = 1 + CompareStrings(s1, s2, i, j + 1, count);
	// Same
	else if (s2[j] == NULL)
		count = 1 + CompareStrings(s1, s2, i + 1, j, count);
	else
	{
		// If same - skip and continue.
		if (s1[i] == s2[j])
			count = CompareStrings(s1, s2, i + 1, j + 1, count);
		// If not - increment count and continue.
		else
			count = 1 + CompareStrings(s1, s2, i + 1, j + 1, count);
	}
	return count;
}