#include <stdio.h>

int main()
{
	int dzielna, dzielnik;
 
	printf("Podaj dzielną: ");
 
	scanf("%d", &dzielna);
 
	printf("Podaj dzielnik: ");
 
	scanf("%d", &dzielnik);
	
	if (dzielnik == 0) {
		printf("\nDzielenie przez 0 jest niewykonalne.\n");
		return 0;
	}
 
	int reszta = dzielna % dzielnik;

	if (reszta == 0) {
		printf ("\nLiczba %d dzieli sie przez %d.\n", dzielna, dzielnik);
	} else {
		printf("\nReszta z dzielenia %d przez %d to %d.\n", dzielna, dzielnik, reszta);
	}

	return 0;
}
