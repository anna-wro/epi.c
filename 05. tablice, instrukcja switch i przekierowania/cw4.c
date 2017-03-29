#include <stdio.h> //funkcie printf i scanf
#include <math.h> //funkcje sin i cos - trzeba kompilować z argumentem -lm

#define KONIEC 0

#define DODAWANIE 1
#define ODEJMOWANIE 2
#define MNOZENIE 3

#define SINUS 10
#define COSINUS 11

double operacja(int numer, double operand_1, double operand_2)
{
	double wynik;
	
	switch(numer)
	{
		case DODAWANIE:
		
			wynik = operand_1 + operand_2;
		
		break;
		
		case ODEJMOWANIE:
		
			wynik = operand_1 - operand_2;
		
		break;
		
		case MNOZENIE:
		
			wynik = operand_1 * operand_2;
		
		break;
		
		case SINUS:
		
			wynik = sin(operand_1);
		
		break;
		
		case COSINUS:
		
			wynik = cos(operand_1);
		
		break;
	}
	
	return wynik;
}

int main()
{
	int m,i;
	
	scanf("%d",&m);
	
	double A[m];
	
	for(i = 0; i < m; ++i) scanf("%lf",&A[i]);
	
	while(1) //pętla potencjalnie nieskończona
	{
		int nr;
		
		scanf("%d", &nr);
		
		if(nr == KONIEC)
		{
			break; //przerwanie pętli
		}
	}
	
	printf("KONIEC\n");
	return 0;
}
