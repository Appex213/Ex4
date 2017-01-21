#include "ex4.h"
#include <stdio.h>
#include <string.h>

int ReverseStrings(char buffer[]);
void PrintStrings(const char str[]);


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

int ReverseStrings(char buffer[])
{
	int i, j;
	char temp;
	int start = -1, end = -1;
	int len = strlen(buffer);

	for (i = 0;i < len;i++) 
	{
		if (buffer[i]!=',' && ((buffer[i] > 91 && buffer[i] < 96) || buffer[i] < 64 || buffer[i]>123))
			return -1;
	}

	for (i = 0; i < len/2 ; ++i)
	{
		temp = buffer[i];
		buffer[i] = buffer[len-1 - i];
		buffer[len-1 - i] = temp;
	}

	for (i = 0;i < len;i++)
	{
		start = -1, end = -1;

		if (buffer[i] != ',')
		{
			start = i;
			for (j = start ; j < len ; ++j)
			{
				if (buffer[j] == ',')
				{
					end = j - 1;
					break;
				}
			}

			if (end == -1)
				end = len-1;
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

void PrintStrings(const char str[])
{
	printf("%s\n", str);
}