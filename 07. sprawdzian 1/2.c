#include <stdio.h>
#include <math.h>

int main(){
	double m;
	double tab[11];
	int i;
	
	printf("Podaj liczbe: ");
	scanf("%lf", &m);

	for (i =1; i<12; i++){
		tab[i] = m/(pow(2, i));
	}
	
	for (i =1; i<12; i++){
		printf("%d: %lf \t\n", i, tab[i]);
	}

return 0;
}
