#include <stdio.h>

int main(){
	int x,y;
	
	for(y = 0; y < 8; ++y)
	{
		for(x = 0; x < 8; ++x)
		{	
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
