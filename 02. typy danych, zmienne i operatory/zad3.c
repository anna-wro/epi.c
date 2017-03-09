#include <stdio.h>

int main()
{
    double a, b;
    
    printf("Podaj dwie liczby: ");
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    
    double suma = a + b;
    double roznica1 = a - b;
    double roznica2 = b - a;
    double mnozenie = a * b;
    double dzielenie1 = a/b;
    double dzielenie2 = b/a;
    
    printf("%.4f + %.4f = %.4f\n", a, b, suma);
    printf("%.4f - %.4f = %.4f\n", a, b, roznica1);
    printf("%.4f - %.4f = %.4f\n", b, a, roznica2);
    printf("%.4f * %.4f = %.4f\n", a, b, mnozenie);
    printf("%.4f / %.4f = %.4f\n", a, b, dzielenie1);
    printf("%.4f / %.4f = %.4f\n", b, a, dzielenie2);

    return 0;
}
