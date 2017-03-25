#include <stdio.h>

void rysuj();

int main(){
	int rozmiar;
	printf("Podaj liczbe: ");
	scanf("%d", &rozmiar);
    rysuj(rozmiar);
    
	return 0;
}

void rysuj(int rozmiar){
	int x, y;
	
    for(y=1; y<=rozmiar; y++){
        for(x=y; x<rozmiar; x++){
            printf(" ");
        }
        for(x=1; x<=(2*y-1); x++){
            printf("*");
        }
        printf("\n");
    }
 
    for(y=rozmiar; y>=1; y--){
        for(x=y; x<=rozmiar; x++){
            printf(" ");
        }
        for(x=2; x<(2*y-1); x++){
            printf("*");
        }
        printf("\n");
    }
}

