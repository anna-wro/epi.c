#include <stdio.h>

int main(){
	int x,y;
	
    for(y=1; y<=8; y++)
    {
        for(x=1; x<=y; x++)
        {
            printf(" ");
        }
        for(x=y; x<=8; x++)
        {
            printf("*");
        }
 
        printf("\n");
    }
    
	return 0;
}

       
