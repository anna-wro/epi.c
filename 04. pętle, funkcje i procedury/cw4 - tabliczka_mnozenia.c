#include <stdio.h>

int main()
{
	int x,y;
	
	for(y = 1; y <= 10; y++)
	{
		for(x = 1; x <= 10; x++)
		{
			printf("%4d", x*y);
		}
		
		printf("\n");
	}
	
	return 0;
}
