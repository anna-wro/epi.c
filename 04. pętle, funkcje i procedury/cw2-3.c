#include <stdio.h>

int silnia (int n)
{
  int sil;
  if (n==0 || n==1) return 1;
  sil = n*silnia(n-1);
  return sil;
}

int main(){
	int i, liczba;
	printf("Podaj liczbe: ");
	scanf("%d", &liczba);
	int wynik = silnia(liczba);
	printf("Silnia: %d\n", wynik);
	
	return 0;
}
