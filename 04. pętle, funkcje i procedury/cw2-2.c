#include <stdio.h>

int main()
{
	int i, liczba;
	printf("Podaj liczbe: ");
	scanf("%d", &liczba);
	int silnia = liczba;
	
	for(i = liczba-1; i >= 1; --i)
	{
		silnia *= i;
	}
	
	printf("Silnia: %d\n", silnia);
	
	return 0;
}
