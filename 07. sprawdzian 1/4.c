#include <stdio.h>

void beta(int * p, int * q){
	*p *= *q;
}

int main(){
	int tab[16] = {1, 2, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
	int i;
	int iloczyn = 1;
	
	for (i =0; i<16; i++){
		beta(&iloczyn, &tab[i]);
	}
	
	printf("Iloczyn tych liczb wynosi: %d\n", iloczyn);
	
return 0;
}
