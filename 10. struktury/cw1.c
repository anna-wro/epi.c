#include <stdio.h>

struct ksiazka {
    char* tytul;
    char* autor;
    int cena;
};

struct ksiazka fabryka(char* tytul, char* autor, int cena) {
    struct ksiazka egz;
    egz.tytul = tytul;
    egz.autor = autor;
    egz.cena = cena;
    
    return egz;
}

void zmien_cene(struct ksiazka * k, int nowa_cena) {
	k->cena = nowa_cena;
	printf("Zmieniono cene ksiazki \"%s\"\n\n", k->tytul);
 }
 
 void wypisz(struct ksiazka x){
 	printf("Tytul: \"%s\" \n", x.tytul);
 	printf("Autor: %s \n", x.autor);
 	printf("Cena: %d zl\n", x.cena);
 	printf("\n");
 }
 
int main() {
	struct ksiazka A[5];
	
	//Adding new books
	A[0] = fabryka("Przedwiośnie", "Żeromski", 25);
	A[1] = fabryka("Nad Niemnem", "Orzeszkowa", 20);
	A[2] = fabryka("Zbrodnia i Kara", "Dostojewski", 15);
	
	// Displaying first book
	wypisz(A[0]);
	
	// Changing the price
	zmien_cene(&A[0], 20);
	
	// Displaying updated results
	wypisz(A[0]);
	
	return 0;
}

