#include "ex4.h"
#include <stdio.h>
#include <string.h>

/*Linux Git Test*/

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
			printf("");
			int size = 9;
			int arr[] = { 45,1,21,3,33,6,53,9,18 };
			MaxSet(arr, size);
			break;
	
		case 3:
			printf("Ender string s1 and s2 and number n:\n");
			char s1[30], s2[30];
			int n;
			scanf("%s", s1);
			scanf("%s", s2);
			scanf("%d", &n);
			DiffersInNChars(s1, s2, n);
			break;
	
		case 4:
			printf("Enter a number: (1 2 3 only!)\n");
			char num[1000];
			scanf("%s", num);
			int isDivisible = DividedBy3(num);
			if (isDivisible)
				printf("Divisible.\n");
			else
				printf("Not divisible.\n");
			break;

		default:
			printf("No such option.\n");
	
	
	}
	
	} while (x!=0);
	return 0;
}


