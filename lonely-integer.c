#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int numIntegers, i, temp, result;
	scanf("%d\n", &numIntegers);

	scanf("%d", &result);
	for (i=0; i<numIntegers-1; i++)
	{
		scanf("%d", &temp);
		result = result ^ temp;
	}
		
	printf("%d\n", result);
	return 0;
}