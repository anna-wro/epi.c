#include <stdio.h>

void zamien(int * x, int * y)
{
	int h = *x;
	*x = *y;
	*y = h;
}

void zeruj(int * c)
{
	*c = 0;
}


int main()
{
	int a = 5, b = 10;
	
	printf("1. Wartości zmiennych: a = %d, b = %d\n\n",a,b);
	printf("2. Adresy zmiennych: a = %p, b = %p\n\n",&a,&b);
	
	int * p = &a;
	
	printf("3. Wskaźnik p pokazuje na zmienną o adresie %p\n\n",p);
	
	//zmieniam wartość zmiennej a za pomocą wskaźnika:
	
	*p = 6;
	
	printf("4. Wartości zmiennych: a = %d, b = %d\n\n",a,b);
	
	//zmieniam wskaźnik na b:
	
	p = &b;
	
	printf("5. Wskaźnik p pokazuje na zmienną o adresie %p\n\n",p);
	
	//zmieniam wartość zmiennej b za pomocą wskaźnika:
	*p = 11;
	
	printf("6. Wartości zmiennych: a = %d, b = %d\n\n",a,b);
	
	//kończymy pracę ze wskaźnikiem p ustawiając go na zero:
	p = NULL;
	//nie wpływa to na zmienne a i b:
	printf("7. Wartości zmiennych wciąż te same: a = %d, b = %d\n\n",a,b);
	
	//wywołujemy funkcję, która powinna zamienić zmienne wartościami
	
	zamien(&a,&b);
	
	printf("8. Wartości zmiennych nadal te same: a = %d, b = %d\n\n",a,b);
	
	//funkcja zerujaca tez dziala dobrze
	
	zeruj(&a);
	zeruj(&b);
	
	printf("9. Obie zmienne równe zero: a = %d, b = %d\n\n",a,b);
	
	return 0;

}
