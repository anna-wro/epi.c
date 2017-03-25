#include <stdio.h>

int main(){
	int x,y;
	
    for(y=0; y<=8; y++)
    {
        for(x=y; x<8; x++)
        {
            printf(" ");
        }
        for(x=1; x<=y; x++)
        {
            printf("*");
        }

        printf("\n");
    }
    
	return 0;
}

       
