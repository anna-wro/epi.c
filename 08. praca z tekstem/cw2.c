#include <stdio.h>

int main() {

	char imie[20];
	
	printf("Jak masz na imie? \n");
	
	fgets(imie,20,stdin);
	
	// imie[0] = 'X';
	// imie[9] = '\0'; - konczy input
	
	printf("Czesc %s",imie);

	return 0;
}
