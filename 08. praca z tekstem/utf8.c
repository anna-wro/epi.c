#include <stdio.h>
#include <string.h>


int utf8chlen (const char * pos)
{
	unsigned short d = (unsigned short)*pos;
	
	if ((d & 128) == 0) return 1;
	if ((d & 224) == 192) return 2;
	if ((d & 240) == 224) return 3;
	if ((d & 248) == 240) return 4;
	
	return -1;
}

int main()
{
	char bfr[200];
	
	fgets(bfr,200,stdin);
	
	int i = 0, c = 0;
	while(bfr[i] != '\0')
	{
		int len = utf8chlen(bfr+i);
		
		if(len == -1)
		{
			printf("Błąd! Niepoprawny kod, niezgodny z UTF-8.\n");
			break;
		}
		
		printf("pozycja %03d, długość %01d, znak: ",c++,len);
		while(len--) printf("%c",bfr[i++]);
		printf("\n");
	}
	
	printf("Tekst zajmuje %d bajtów, a zawiera %d znaków UTF-8.\n",i,c);

	return 0;

}