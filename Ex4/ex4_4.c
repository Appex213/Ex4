#include "ex4.h"
#include <stdio.h>
#include <string.h>

int CheckSumMod3(char str[], int len, int i, int sum);

int DividedBy3(char str[])
{
	if (!strlen(str))
		return 1;
	if (!CheckSumMod3(str, strlen(str), 0, 0))
		return 1;
	else
		return 0;
}

int CheckSumMod3(char str[],int len, int i,int sum)
{
	if (i < len)
		sum = CheckSumMod3(str, len, i + 1, sum);

	if (str[i] == '2')
	{
		if (sum == 0)
			sum = 2;
		else if (sum == 1)
			sum = 0;
		else if (sum == 2)
			sum = 1;
	}
	if (str[i] == '1')
	{
		if (sum == 0)
			sum = 1;
		else if (sum == 1)
			sum = 2;
		else if (sum == 2)
			sum = 0;

	}
	return sum;
}