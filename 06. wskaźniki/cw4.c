#include <stdio.h>
#define GORA 8
#define DOL 2
#define LEWO 4
#define PRAWO 6


int graczx, graczy; //pozycja gracza we współrzędnych x,y - zmienne globalne, widoczne we wszystkich funkcjach

void inicjalizuj(char * T, int skarbx, int skarby)
{
//1. wykonanie kwadratu z kropek

	int i;
	
	for(i = 0; i < 9*9; ++i)
	{
		*(T+i) = '.';
	}
	
//2. umieszczenie skarbu
	
	*(T+9*skarby+skarbx) = 'S';
	
//3. umieszczenie gracza

	*(T+9*graczy+graczx) = 'G';
}



void wypisz(char * T)
{
//wypisanie aktualnego stanu planszy na ekran

	int x,y;
	for(y = 0; y < 9; ++y)
	{
		for(x = 0; x < 9; ++x)
		{
			printf("%c",*(T+9*y+x));
		}
		printf("\n");
	}
}

int ruch_gracza(char * T, int kierunek)
{
	int status = -1;
	
	int nowyx = graczx, nowyy = graczy;
	
	switch(kierunek)
	{
		case GORA:
			--nowyy;
		break;

		case DOL:
			++nowyy;
		break;

		case LEWO:
			--nowyx;
		break;

		case PRAWO:
			++nowyx;
		break;

		default:
			return -1;
		break;
	}
	
	if(nowyy >= 0 && nowyy < 9 && nowyx >= 0 && nowyx < 9)
	{
		//zamazanie starej pozycji
		*(T+9*graczy+graczx) = ' ';
		
		//badanie nowej pozycji
		status = 0;
		
		if(*(T+9*nowyy+nowyx) == 'S') status = 1;
		
		//aktulizacja pozycji gracza
		graczx = nowyx;
		graczy = nowyy;
		
		//narysowanie gracza w nowej pozycji
		*(T+9*graczy+graczx) = 'G';
	}
	
	return status;
}

int main()
{
	char P[9*9]; //alokacja pamięci na planszę gry
	
	graczx = 0; //ustanowienie początkowej pozycji gracza
	graczy = 0;
	
	inicjalizuj(P,4,4); //wypełnienie planszy wartościami początkowymi
	
	wypisz(P); //wypisanie początkowej planszy na ekran
	
	int status;
	do {
		int input;
		printf("Podaj kierunek (8 6 2 4): ");
		
		scanf("%d",&input); //pobranie decyzji gracza
		
		status = ruch_gracza(P,input); //obsługa ruchu gracza
		
		wypisz(P); //wypisanie nowego stanu planszy na ekran
	}
	while(status != 1); //gra działa, dopóki gracz nie znajdzie skarbu
	
	if(status == 1) printf("Gratulacje, otrzymujesz 8000000000000000000 punktów.\n");

	return 0;

}