/*
https://www.hackerrank.com/challenges/game-of-thrones

sample input: cdefghmnopqrstuvw , output:NO
sample input2: cdcdcdcdeeeef, output: YES

TODO: look into supressing warnings
*/

#include<stdio.h>
#include<stdlib.h>

#define ALPHABET_COUNT 26

// Returns the integer key to look up character in my awesome DIY hashmap
// assumption is that input is from 'a' to 'z'
int getKey(char value)
{
	return (value - '0');
}


int checkIfAnagramIsPalindrome(char * input, int length)
{
	int i, result;
	int * diyCHashMap; // a hashMap where each index is used to store the count of each small case alphabet in input
	int numOddElements, numEvenElements, numOnceElems = 0;


	diyCHashMap = (int *)calloc(ALPHABET_COUNT, sizeof(int));

	for(i=0;i<length;i++)
		diyCHashMap[getKey(input[i])] += 1;

	for(i=0; i<ALPHABET_COUNT; i++)
	{
		if(diyCHashMap[i] % 2 == 0)
			numEvenElements++;
		else
		{
			if(diyCHashMap[i] == 1)
				numOnceElems++;
			else
				numOddElements++;
		}

	}

	
	if(numOnceElems > 1 || numOddElements%2 != 0)
		return 0;
	else 
		return 1;
}


int main()
{
	char input[100000];

	gets(input);

	if(checkIfAnagramIsPalindrome(input, strlen(input)))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}