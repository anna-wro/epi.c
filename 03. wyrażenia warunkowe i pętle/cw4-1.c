#include <stdio.h>

int main()
{
	int i;

	for(i = 0; i < 11; ++i)
	{
		if(i % 2 != 0) printf("%d ",i);
	}
	
	printf("\n");

	return 0;
}
