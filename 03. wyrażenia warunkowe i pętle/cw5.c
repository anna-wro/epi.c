#include <stdio.h>

int main(){
	int i, liczba, dzielnik;
	printf("Podaj liczbe calkowita: ");
	scanf("%d", &liczba);
	for(i=1; i<=liczba; i++){
		if (liczba % i == 0) dzielnik++;
	}
	if (dzielnik>2) {
		printf("\n%d ma %d dzielnikow\n", liczba, dzielnik);
	} else {
		printf("\n%d jest liczba pierwsza.\n", liczba);
	}
	return 0;
}
