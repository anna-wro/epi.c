#include <stdio.h>

int main(){
	int x,y;
	 
	for(y = 0; y < 8; y++)
	{
		for(x=0; x<8; x++)
        {
            if(y==0 || y==7 || x==0 || x==7)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
	}
	
	return 0;
}
