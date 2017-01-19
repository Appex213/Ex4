#include "ex4.h"
#include <stdio.h>
#include <string.h>

int main()
{
	
	int x;
	do {
	printf("Enter programm #(1-4):\n");
	scanf("%d",&x);

	switch (x)
	{
		case 1:
			printf("Enter string to reverse:\n");
			char str[1000];
			scanf("%s", str);
			ReverseStringsManager(str);
			break;
	
		case 2:
			break;
	
		case 3:
			break;
	}
	
	} while (x!=0);
	return 0;
}