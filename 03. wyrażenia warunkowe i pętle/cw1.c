#include <stdio.h>

int main()
{
	int a;

	printf("Podaj jedną liczbę całkowitą: ");

	scanf("%d",&a);


	if(a > 0)
	{
		printf(" 1. Liczba %d jest dodatnia.\n",a);
	}
	else if(a == 0)
	{
		printf(" 2. Liczba jest równa zero.\n");
	}
	else
	{
		printf(" 3. Liczba %d jest ujemna.\n",a);
	}



	if(a >= 0)
	{
		printf(" 4. Liczba %d jest nieujemna.\n",a);
	}



	if(a <= 0)
	{
		printf(" 5. Liczba %d jest niedodatnia.\n",a);
	}



	if(a != 0)
	{
		printf(" 6. Liczba %d jest różna od zera.\n",a);
	}



	if(a)
	{
		printf(" 7. Liczba niezerowa ma wartość logiczną prawda.\n");
	}
	else
	{
		printf(" 8. Liczba zero ma wartość logiczną fałsz.\n");
	}


	return 0;
}