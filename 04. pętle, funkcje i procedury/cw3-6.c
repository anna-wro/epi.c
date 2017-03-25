#include <stdio.h>

int main(){
	int x,y;
	
	for(y = 0; y < 8; ++y)
	{
		for(x = 1; x<y; x++)
		{	
			printf(" ");
		}
		
		for(x = 0; x < 3; ++x)
		{	
		    if((y==0||y==7)&&x==2) break;
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
