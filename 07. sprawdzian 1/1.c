#include <stdio.h>

int main(){
	int tab[4];
	int i;
	for (i =0; i<4; i++){
		scanf("%d", &tab[i]);
	}
	printf("Druga lub trzecia liczba nie jest najwieksza z nich wszystkich\n");
	if((tab[1]>tab[0]&&tab[1]>tab[2]&&tab[1]>tab[3]) 
	|| (tab[2]>tab[0]&&tab[2]>tab[1]&&tab[2]>tab[3])){
		printf("NIE\n"); // bo jest najwieksza
	} else {
		printf("TAK\n");
	}

return 0;
}
