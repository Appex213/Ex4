#include "ex4.h"
#include <stdio.h>

int CheckIfEqual(char s1[], char s2[], int i, int j, int count);

void DiffersInNChars(char s1[], char s2[], int n)
{
	if (CheckIfEqual(s1, s2, 0, 0, 0) == n)
		printf("yes\n");
	else
		printf("no\n");
	
}

int CheckIfEqual(char s1[], char s2[], int i, int j, int count)
{
	if (s1[i] == NULL && s2[j] == NULL)
		return 0;
	else if (s1[i] == NULL)
		count = 1 + CheckIfEqual(s1, s2, i, j + 1, count);
	else if (s2[j] == NULL)
		count = 1 + CheckIfEqual(s1, s2, i + 1, j, count);
	else
	{
		if (s1[i] == s2[j])
			count = CheckIfEqual(s1, s2, i + 1, j + 1, count);
		else
			count = 1 + CheckIfEqual(s1, s2, i + 1, j + 1, count);
	}
	return count;
}