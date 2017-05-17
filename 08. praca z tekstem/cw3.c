#include <stdio.h>

int main() {

	char bufor[100];
	
	printf("Wprowadz jakis tekst: \n");
	
	fgets(bufor,100,stdin);
	
	printf("Podany tekst ma %lu znakow\n", strlen(bufor));

	return 0;
}
