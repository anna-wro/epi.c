#include <stdio.h>
#pragma pack(push)  //zapamiętanie aktualnej wartości zaokrąglania
#pragma pack(1)     //ustawienie zaokrąglania na 1 bajt

struct naglowek {
	unsigned short signature;
	unsigned int file_size;
	unsigned short reserved;
	unsigned short reserved2;
	unsigned int offset;
    unsigned int header_size;
    unsigned int image_width;
    unsigned int image_height;
    unsigned short planes;
    unsigned short bits_per_pixel;
};

#pragma pack(pop)   //przywrócenie standardowych ustawień
 
int main() {

	FILE * fp = fopen("obrazek.bmp","r");   // na platformie Windows koniecznie "rb"

	struct naglowek n;                      // utworzenie zmiennej na złapanie nagłówka

	fread(&n, sizeof(n), 1, fp);            // wczytanie z pliku do n

	fclose(fp);                             // zamknięcie pliku
	
	printf("File size: %u bytes \n", n.file_size);
	printf("Image width: %u \n", n.image_width);
	printf("Image height: %u \n", n.image_height);

	return 0;
}

