#include <stdio.h>

int main()
{
	int i;

	for(i = 11; i < 100; ++i)
	{	
		printf("%d ",i);
		if (i % 10 == 0) printf ("\n");
	}
	
	printf("\n");

	return 0;
}
