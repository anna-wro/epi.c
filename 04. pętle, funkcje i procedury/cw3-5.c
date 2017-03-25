#include <stdio.h>

int main(){
	int x,y;
	
    for(y=0; y<=8; y++)
    {
       if(y%2==1) printf(" ");
       for(x=0; x<4; x++)
        {
            printf("* ");
        }
        printf("\n");
    }
    
	return 0;
}

       
