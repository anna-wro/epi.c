#include <stdio.h>

int main()
{
    int a, b;
    
    printf("Podaj dwie liczby: ");
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    int suma = a + b;
    int roznica1 = a - b;
    int roznica2 = b - a;
    int mnozenie = a * b;
    int dzielenie1 = a / b;
    int dzielenie2 = b / a;
    int modulo1 = a % b;
    int modulo2 = b % a;
    
    printf("%d + %d = %d\n", a, b, suma);
    printf("%d - %d = %d\n", a, b, roznica1);
    printf("%d - %d = %d\n", b, a, roznica2);
    printf("%d * %d = %d\n", a, b, mnozenie);
    printf("%d / %d = %d\n", a, b, dzielenie1);
    printf("%d / %d = %d\n", b, a, dzielenie2);
    printf("%d %% %d = %d\n", a, b, modulo1);
    printf("%d %% %d = %d\n", b, a, modulo2);
    
    return 0;
}