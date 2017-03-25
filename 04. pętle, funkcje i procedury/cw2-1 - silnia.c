#include <stdio.h>

int main()
{
	int i, liczba;
	int silnia = 1;
	printf("Podaj liczbe: ");
	scanf("%d", &liczba);
	
	for(i = 1; i <= liczba; i++)
	{
		silnia *= i;
	}
	
	printf("Silnia: %d\n", silnia);
	
	return 0;
}
