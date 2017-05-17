#include <stdio.h>

int main() {

	char napis1[] = {'W', 'i', 't', 'a', 'j', '\0'};
	char napis2[] = "Witaj";
	
	if (strcmp (napis1, napis2) == 0) {
		printf("Napisy sa takie same\n");
	} else {
		printf("Napisy sa inne!\n");
	}

	return 0;
}
