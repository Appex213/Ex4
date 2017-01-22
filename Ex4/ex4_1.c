/******************************************
* Matan Ben Moshe
* 208583070
* 83-120-04
* ex4_1.c
******************************************/

//Header file.
#include "ex4.h"
//Standard library.
#include <stdio.h>
//String library.
#include <string.h>

// Declerations
int ReverseStrings(char buffer[]);
void PrintStrings(const char str[]);


/*********************************************************************************************
Function name: ReverseStringsManager
Input: string
Output: none
The function operation: Recieves a string and prints it. Checks for empty string, then calls ReverseStrings to reverse word order in the string or return invalid string, and prints accordingly.
**********************************************************************************************/
void ReverseStringsManager(char str[])
{
	printf("The word list: ");
	PrintStrings(str);
	if (strlen(str)==0)
		printf("Reverse: ");
	else if (ReverseStrings(str))
		printf("The list is illegal!\n");
	else
	{
		printf("Reverse: ");
		PrintStrings(str);
	}



}


/*********************************************************************************************
Function name: ReverseStrings
Input: String
Output: 0 if reversed, -1 if rejected.
The function operation: Recieves a string and checks for invalid characters. Then reverses entire string, and in turn reverses back every word.
**********************************************************************************************/
int ReverseStrings(char buffer[])
{
	int i, j;
	char temp;
	int start = -1, end = -1;
	int len = strlen(buffer);

	// Check for invalid chars in string (not a-z,A-Z, or ',')
	for (i = 0;i < len;i++) 
	{
		if (buffer[i]!=',' && ((buffer[i] > 'Z' && buffer[i] < 'a') || buffer[i] < 'A' || buffer[i]>'z'))
			return -1;
	}
	// String reverse loop
	for (i = 0; i < len/2 ; ++i)
	{
		temp = buffer[i];
		buffer[i] = buffer[len-1 - i];
		buffer[len-1 - i] = temp;
	}
	// Word reverse loop
	for (i = 0;i < len;i++)
	{
		start = -1, end = -1;

		// Check for word start
		if (buffer[i] != ',')
		{
			start = i;
			for (j = start ; j < len ; ++j)
			{
				// Check for word end
				if (buffer[j] == ',')
				{
					end = j - 1;
					break;
				}
			}

			if (end == -1)
				end = len-1;
			//Reverse word
			for (j = start ; j <= (start + end) / 2 ; ++j)
			{
				temp = buffer[j];
				buffer[j] = buffer[end - (j-start)];
				buffer[end - (j-start)] = temp;
			}
			i = end;
		}
	}

	return 0;
}

/*
Literaly a single line of code. Was if really necessary to do this in a function?
Anyway, yeah. Its a function called PrintStrings. Guess what it does. Go on. Yeah, it prints strings.
How?. Well, through a single line of code, with the simplest possible command.
So why an entire function you ask? cuz thats what they wanted. 
Why am I even writing this?
*/
void PrintStrings(const char str[])
{
	printf("%s\n", str);
}