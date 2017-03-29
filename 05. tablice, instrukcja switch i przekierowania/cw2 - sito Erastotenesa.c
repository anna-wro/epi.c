#include <stdio.h>

#define SKRESLONA 0
#define NIESKRESLONA 1

int main()
{
	char T[1001];
	
	int i,j;
	
	for(i = 2; i < 1001; ++i) T[i] = NIESKRESLONA;
	
	for(i = 2; i < 1001; ++i)
	{
		if(T[i] == SKRESLONA) continue;
		
		for(j = 2; j*i < 1001; ++j)
		{
			 T[i*j] = SKRESLONA;
		}
	}
	
	for(i = 2; i < 1001; ++i)
		if(T[i] == NIESKRESLONA) printf("%d ",i);
	
	printf("%c",'\n');
		
	return 0;
}
