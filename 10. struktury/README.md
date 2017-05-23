# Struktury 

Struktury pozwalają tworzyć własne typy danych w postaci kombinacji istniejących typów prostych lub innych struktur. Bardziej zaawansowana praca ze strukturami nosi nazwę programowanie obiektowe i jest dostępna w językach takich jak np. C++, Java, C#, D, Smalltalk, PHP i innych. W języku C mechanizm struktur jest bardzo uproszczony, ale ciągle bardzo użyteczny.

Strukturę deklaruje się tak:

    struct para
    {
        int x;
        int y;
    };

W ten sposób stworzyliśmy nowy typ danych o nazwie `para`, który składa się z dwóch wartości typu `int`, dostępnych pod identyfikatorami odpowiednio x i y. **Zwracam uwagę na średnik kończący deklarację struktury** - to jest trochę inaczej niż przy np. if, for, while, gdzie po nawiasie zamykającym nie trzeba dawać średnika.

Deklaracje struktur umieszcza się powyżej wszystkich funkcji w danym pliku, albo w osobnym pliku nagłówkowym, np. `para.h`, który potem dołącza się do głównego pliku poleceniem `#include "para.h"`.

Mając już zadeklarowany nowy typ, możemy gdzieś w funkcjach utworzyć zmienną tego typu:

    struct para p;
    
Powyżej utworzyliśmy zmienną o nazwie `p` typu `para`. Dostęp do pól tej zmiennej jest za pomocą operatora kropka, np.

    p.x = 5;
    p.y = 3;

Można też utworzyć wskaźnik, wówczas dostęp do pól jest z użyciem operatora strzałka:

    struct para * w = &p; //ustawienie wskaźnika w na adres zmiennej p

    w->x = -1; //zmiana pola x w zmiennej p

    w->y = -4; //zmiana pola y w zmiennej p

Struktura może być argumentem funkcji, np.

    void wypisz(struct para a)
    {
        printf("(%d, %d)", a.x, a.y);
    }

Struktura może być też zwracana przez funkcję - taką funkcję żargonowo nazywa się fabryką, np.

    struct para fabryka(int a, int b)
    {
        struct para produkt;

        produkt.x = a;
        produkt.y = b;

        return produkt;
    }
    
### Ćwiczenie 1

1. Utwórz strukturę książka, zawierającą pola: tytuł (char *), autor (char *), cena (int).
1. W funkcji main() utwórz tablicę typu książka o pojemności przynajmniej na kilka książek.
1. Utwórz fabrykę książek, typu np. `struct ksiazka fabryka(char * tytul, char * autor, int cena)`.
1. W main() wypełnij tablicę książek używając fabryki, np. `A[0] = fabryka("Przedwiośnie", "Żeromski", 25);`
1. Utwórz funkcję do zmiany ceny, np. `void zmien_cene(struct ksiazka * k, int nowa_cena)`
1. Utwórz funkcję wypisującą tytuł, autora i cenę na ekran, np. `void wypisz(struct ksiazka x)`
1. Napisz w main kod demonstrujący zmianę ceny i wypisywanie.

### Ćwiczenie 2

Wielkość struktur w języku C jest automatycznie zaokrąglana do równych 4 bajtów. Z tego powodu struktura:

    struct x
    {
        int a;
        char b;
    }

po wywołaniu kodu:

    printf("%d", sizeof(struct x));

widać, że ma rozmiar 8 bajtów, mimo, że oba pola w sumie zajmują tylko 5. W normalnych zastosowaniach zaokrąglanie do wielokrotności 4 bajtów jest korzystne, ponieważ np. przyspiesza operacje kopiowania w pamięci. Jednak czasami potrzebne jest, żeby struktura była dokładnie takiej wielkości, jak wynika z zawartych w niej pól. Można przełączyć to zestawem poleceń:

    #pragma pack(push)  //zapamiętanie aktualnej wartości zaokrąglania
    #pragma pack(1)     //ustawienie zaokrąglania na 1 bajt
    
    //tutaj deklaracja struktury
    
    #pragma pack(pop)   //przywrócenie standardowych ustawień

W tym artykule https://en.wikipedia.org/wiki/BMP_file_format znajduje się rysunek formatu pliku BMP. Utwórz strukturę (z włączonym zaokrągleniem do 1 bajtu), odpowiadającą nagłówkowi pliku BMP, przynajmniej do pola Image Height włącznie. Do zmiennych 2-bajtowych należy użyć `unsigned short`, do 4-bajtowych `unsigned int`. Następnie znajdź w Internecie lub utwórz samemu w programie graficznym plik BMP, otwórz go w swoim programie i wczytaj nagłówek np. tak:

    FILE * fp = fopen("obrazek.bmp","r");   // na platformie Windows koniecznie "rb"
    
    struct naglowek n;                      // utworzenie zmiennej na złapanie nagłówka
    
    fread(&n, sizeof(n), 1, fp);            // wczytanie z pliku do n
    
    fclose(fp);                             // zamknięcie pliku

Następnie wypisz na ekran zawartość pól File Size, Image Width, Image Height i sprawdź, czy się zgadzają.
