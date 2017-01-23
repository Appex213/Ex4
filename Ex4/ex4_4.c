/******************************************
* Matan Ben Moshe
* 208583070
* 83-120-04
* ex4_4.c
******************************************/

//Header file.
#include "ex4.h"
//Standard library.
#include <stdio.h>
//String library.
#include <string.h>
//Decleration
int CheckMod3(char str[], int sum);

/*********************************************************************************************
Function name: DividedBy3
Input: string of 1,2,3
Output: 1 if divisible, 0 if not.
The function operation: Checks for empty string (counts as 0 - divisible). 
						If not - calls to CheckMod3 to get the remainder from division by 3. Returns 1 or 0 accordingly.
**********************************************************************************************/
int DividedBy3(char str[])
{
	// !0 = true (== return true if input is empty)
	if (!strlen(str))
		return 1;
	// !0 = true (== if remaider is 0 the number is divisible)
	if (!CheckMod3(str, 0))
		return 1;
	else
		return 0;
}

/*********************************************************************************************
Function name: CheckMod3
Input: string of 1,2 and 3 and initial remainder.
Output: remainder.
The function operation: Goes to end of string, then goes back, adding and resseting the remainder every time it passes 3.
**********************************************************************************************/
int CheckMod3(char str[],int sum)
{
	// Stop Condition - go to the end of the string and then return
	if (strlen(str) > 1)
		sum = CheckMod3(str + 1, sum);

	// Pretty self explenatory - add to sum and reset when sum is 3 (3=0, 4=1 etc.) 
	if (str[0] == '2')
	{
		if (sum == 0)
			sum = 2;
		else if (sum == 1)
			sum = 0;
		else if (sum == 2)
			sum = 1;
	}
	if (str[0] == '1')
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