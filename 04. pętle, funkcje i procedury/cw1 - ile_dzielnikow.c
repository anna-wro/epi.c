int ile_dzielnikow(int liczba)
{
	//zmienna liczba jest argumentem funkcji - zawiera daną wejściową
	
	int dzielnik = 0;
	int i;
	
	for(i=1; i<=liczba; i++){
		if (liczba % i == 0) dzielnik++;
	}
	
	return dzielnik; //tędy należy wyprowadzić wynik zamiast liczby 2
}


#include <stdio.h>

int main()
{
	int i;
	
	for(i = 2; i <= 1000; ++i)
	{
		int liczba_dzielnikow = ile_dzielnikow(i);
		
		if(liczba_dzielnikow == 2)
		{
			printf("%d ",i);
		}
	}
	
	printf("\n");
	
	return 0;
}
