#include <stdio.h>
#include <math.h>

int main(){
	double bok1, bok2, poleProstokata, poleKwadratu, bokKwadratu, obwod;
	
	printf("Podaj boki prostokata: ");
	scanf("%lf %lf", &bok1, &bok2);
	
	poleProstokata = bok1 * bok2;
	printf("Pole prostokata wynosi: %lf\n", poleProstokata);
	
	obwod = 2*bok1 + 2*bok2;
	bokKwadratu = obwod/4;
	poleKwadratu = pow(bokKwadratu, 2.0);
		
	printf("Pole to stanowi %lf pola kwadratu o takim samym obwodzie\n", poleProstokata / poleKwadratu);

return 0;
}
