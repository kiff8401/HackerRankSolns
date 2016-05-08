/*
https://www.hackerrank.com/challenges/the-love-letter-mystery

Read from std-in , print to std-out

Sample input :
4
abc
abcba
abcd
cba

Sample output:
2
0
4
2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getAlphabetDifference(char a, char b)
{
	return abs(b-a);
}

int getNumOperationsForInput(char * input, int length)
{
	int result = 0;
	int i;
	int last = length -1;
	int midElementIndex = length/2;

	for(i=0;i<midElementIndex;i++)
	{
		result += getAlphabetDifference(input[i], input[last-i]);
	}

	return result;
}

int main() 
{
	int numTestCases ;
	int i, count;
	char c;
	char stringInput[100]; // TODO: Figure out a better default memory allocation
	int * results ; 

	scanf("%d", &numTestCases);
	scanf("%c", &c); // gets the newline as well

	results = (int *) malloc(numTestCases*sizeof(int));

	for(i=0;i<numTestCases;i++)
	{
		// TODO: this is pure C, could use gets() as well
		count = 0;
 		do
		{
			scanf("%c", &c);
			stringInput[count++] = c;		
		} while(c != '\n');

		results[i] = getNumOperationsForInput(stringInput, count-1);
	}


	for (i=0;i<numTestCases;i++)
		printf("%d\n", results[i]);

	return 0;
}