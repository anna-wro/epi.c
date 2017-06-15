#include <stdio.h>
#define SIZE 100

int A[SIZE], B[SIZE];

void Read(int T[], int len){
	int i, j;
	T[len];

	for(i=0; i<len; i++){
		printf("Podaj %d element zbioru\n", (i+1));
		scanf("%d", &j);
		int check = 0;
		int k;
			for(k=0; k<len; k++) {
				if(T[k] == j) {
					check = 1;
				}
			}
			if(check != 1){
				T[i] = j;
			}
			else{
				i--;
				printf("Ten element juz był\n");
			}
	};	
};

void Write(int T[], int len){
	int i;
	for(i=0; i<len; i++){
		
		if(i>0 && i % 10 == 0){
			printf("\n");
			printf("%d ", T[i]);
		}
		else{
		printf("%d ", T[i]);
		}
	};
};

int Find(int T[], int len, int x) {
  for (int i = 0; i < len; ++i){
    if (T[i] == x) return 1;
  }
  return 0;
}

// Suma zbiorów
void Sum(int A[], int nA, int B[], int nB){
  int i;
  for (i = 0; i < nA; i++) {
    printf("%d ", A[i]);
  }

  for (i = 0; i < nB; ++i) {
    // wypisujemy tylko jeśli tej liczby nie było w zbiorze A
    if (!Find(A, nA, B[i]))
      printf("%d ", B[i]);
  }
  printf("\n");
}

// Część wspólna zbiorów (A∩B) 
void Product(int A[], int nA, int B[], int nB) {
    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            if (A[i] == B[j]) printf("%d ", A[i]);
    }
  }
  printf("\n");
}

// Różnica zbiorów (A\B)
void Difference(int A[], int nA, int B[], int nB){
    for (int i = 0; i < nA; i++) {
        // wypisujemy tylko jeśli liczby nie ma w zbiorze B
		if (!Find(B, nB, A[i])) {
			printf("%d ", A[i]);
		}
    }
}

// Inkluzja - A ⊂ B 
// Każdy element zbioru A jest w zbiorze B
int Inclusion (int A[], int nA, int B[], int nB){
    if (nA > nB) return 0;
    for (int i = 0; i < nA; ++i) {
        int takieSame = 0;
        for (int j = 0; j < nB; ++j) {
            if (A[i] == B[j]) takieSame = 1;
        }
        // jeśli A[i] nie ma nigdzie w B zwracamy fałsz
        if (!takieSame) return 0;
  }
  return 1;
}

int Equality (int A[], int nA, int B[], int nB){
    if (nA == nB && Inclusion(A, nA, B, nB)){
        return 1;
    } else {
        return 0;
    }
}

int main() {
  
    int nA, nB;
    
    // Wczytywanie liczb
    printf("Ile liczb wczytac do zbioru A?\n");
    scanf("%d", &nA);
    int A[nA];
    printf("Wpisz kolejne liczby:\n");
    Read(A, nA);
    printf("\nIle liczb wczytac do zbioru B?\n");
    scanf("%d", &nB);
    int B[nB];
    printf("Wpisz kolejne liczby:\n");
    Read(B, nB);
    
    printf("Zbiór A:\n");
    Write(A, nA);
    
     printf("\nZbiór B:\n");
    Write(B, nB);
    
    // Suma zbiorów
    printf("\nSuma zbiorow A i B:\n");
    Sum(A, nA, B, nB);

    // Część wspólna 
    printf("Część wspólna zbiorów A i B:\n");
    Product(A, nA, B, nB);
   
    // Różnica zbiorów
    printf("Różnica zbiorów A\\B:\n");
    Difference(A, nA, B, nB);
    printf("\n");
    
    // Inkluzja
    if(Inclusion(A, nA, B, nB)){
         printf("Zbiór A jest podzbiorem zbioru B.\n");
    } else { 
        printf("Zbiór A nie jest podzbiorem zbioru B.\n");
    } 
    if(Inclusion(B, nB, A, nA)){
         printf("Zbiór B jest podzbiorem zbioru A.\n");
    } else { 
        printf("Zbiór B nie jest podzbiorem zbioru A.\n");
    } 

   // Takie same zbiory
    if(Equality(A, nA, B, nB)) {
        printf("Zbiory A i B są równe.\n");
    } else {
        printf("Zbiory A i B nie są równe.\n");
    }
              
  return 0;
}





