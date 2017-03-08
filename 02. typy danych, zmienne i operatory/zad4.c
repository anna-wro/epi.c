#include <stdio.h>

int main()
{
    double a;
    int b;
    
    printf("Podaj dwie liczby: ");
    
    scanf("%lf", &a);
    scanf("%d", &b);
    
    int a1 = a;
    double b1 = b;
    double a2 = a1;
    
    printf("\na\t= %f\na1\t= %d\na2\t= %f\nb\t= %d\nb1\t= %f\n\n", a, a1, a2, b, b1);
    
    printf("a + a1\t= %f\n", a + a1);
    printf("a + a2\t= %f\n", a + a2);
    printf("a + b\t= %f\n", a + b);
    printf("a + b1\t= %f\n", a + b1);
    printf("a1 + b\t= %d\n", a1 + b);
    printf("a1 + b1\t= %f\n\n", a1 + b1);
    
    int c = a + b1;
    
    printf("c\t= %d\n\n", c);
    
    short d = c;
    
    printf("d\t= %hd\n\n", d);
    
    char e = d;
    
    printf("e\t= %hhd\n\n", e);
    
    return 0;


}