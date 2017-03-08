#include <stdio.h> //dostęp do funkcji printf i scanf

int main()
{

    char a, b; //utworzenie zmiennych a i b typu char
    
    a = 'A'; //ustawienie wartosci a na kod znaku A
    b = 66; //ustawienie wartosci b na kod znaku B
    
    printf("Powinny zostac wypisane znaki:\t %c %c \n",a,b);
    printf("Powinny zostac wypisane liczby:\t %hhd %hhd \n",a,b);
    
    short c = 100; //utworzenie zmiennej typu short i ustawienie pierwszej wartosci
    int d = 100; //utworzenie zmiennej typu int i ustawienie pierwszej wartosci
    
    printf("Powinny zostac wypisane liczby:\t %hd %d \n",c,d);
    
    int dlugosc;
    
    dlugosc = sizeof(a);
    
    printf("Dlugosc zmiennej typu char to %d bajt(y/ow).\n",dlugosc);
    
    dlugosc = sizeof(c);
    
    printf("Dlugosc zmiennej typu short to %d bajt(y/ow).\n",dlugosc);
    
    dlugosc = sizeof(d);
    
    printf("Dlugosc zmiennej typu int to %d bajt(y/ow).\n",dlugosc);
    
    return 0;
}
