#include <stdio.h>

int main()
{
	int tabl[] = {1, 10, 1, 100, 1, 1000, 1};
	int tabl2[7];
	int i;
	int j = 6;
	
	for(i = 0; i < 7; ++i)
	{
		printf("tabl[%d] = %d\n", i, tabl[i]);
	}
	
	for(i = 0; i < 7; ++i){
		tabl2[j] = tabl[i];
		j--;
	}
	
		for(i = 0; i < 7; ++i)
	{
		printf("tabl2[%d] = %d\n", i, tabl2[i]);
	}
	
	return 0;
}


