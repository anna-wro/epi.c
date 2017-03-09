#include <stdio.h>

int main(){
	char a;
	unsigned int b;
	float c;
	
	int dlugosc = sizeof(a);
	printf("Dlugosc zmiennej typu char to %d bajt(y/ow).\n",dlugosc);
	
	dlugosc = sizeof(b);
	printf("Dlugosc zmiennej typu unsigned int to %d bajt(y/ow).\n",dlugosc);
	
	dlugosc = sizeof(c);
	printf("Dlugosc zmiennej typu float to %d bajt(y/ow).\n",dlugosc);
	
	a = 'A';
	b = 5;
	c = 1.2;
	printf("Wartosci zmiennych: a - %c, b - %u, c - %.2f\n", a, b, c);
	
	return 0;
}
