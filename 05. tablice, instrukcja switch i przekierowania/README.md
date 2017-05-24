# Tablice, instrukcja switch i przekierowania

Podręcznik Wikibooks: [tablice](https://pl.wikibooks.org/wiki/C/Tablice), [switch](https://pl.wikibooks.org/wiki/C/Instrukcje_steruj%C4%85ce#switch), [continue](https://pl.wikibooks.org/wiki/C/Instrukcje_steruj%C4%85ce#continue). Wikipedia: [Sito Erastotenesa](https://pl.wikipedia.org/wiki/Sito_Eratostenesa).

### **Ćwiczenie 1:**

Plik cw1.c zawiera deklarację tablicy typu int wraz z listą jej początkowych wartości. Tablica taka posiada dokładnie tyle elementów, ile jest wartości na tej liście. Jest tam też pętla do wyświetlania zawartości tablicy na ekranie. Rozbuduj program następująco:

 1. Zadeklaruj własną tablicę 7-elementową int. Deklaracja tablicy ma postać: typ nazwa[rozmiar];. Następnie napisz pętlę, która skopiuje zawartość tablicy tabl w odwrotnej kolejności, tzn. wartość ostatniej komórki, czyli tabl[6] będzie miała w nowej tablicy indeks 0, zaś wartość pierwszej komórki, czyli tabl[0] będzie ostatnią w nowej tablicy. Następnie wyświetl nową tablicę na ekranie tak, jak wyświetlana jest tabl.
2. Zadeklaruj jeszcze jedną tablicę 7-elementową. Napisz pętlę, która wypełni tą tablicę wartościami tak, żeby i-ta komórka tej tablicy zawierała sumę od 0 do i komórek tablicy z poprzedniego punktu. Następnie wyświetl tablicę na ekranie tak, jak w poprzednim punkcie.

### **Ćwiczenie 2: Sito Erastotenesa**

Sito Erastotenesa jest to algorytm służący do wyznaczania liczb pierwszych metodą skreślania. Załóżmy, że mamy wypisane liczby od 2 do 1000. Pierwszą z nich jest 2, więc skreślamy jej wielokrotności 4, 6, 8, 10 itd. Następnie przechodzimy do liczby 3. Nie jest skreślona, więc jest liczbą pierwszą, więc skreślamy jej wielokrotności: 6, 9, 12, 15, 18 itd. Następnie przechodzimy do 4, która została skreślona, więc ją pomijamy. Przechodzimy więc do 5, która nie została skreślona, więc skreślamy jej wielokrotności... I tak dalej, aż dojdziemy do 1000. Te liczby, które nie zostały skreślone, są liczbami pierwszymi.

Program cw2.c zawiera prawie kompletne Sito Erastotenesa. Na razie działa źle, bo nie skreśla - skompiluj i uruchom.

1. Dodaj we właściwym miejscu odpowiednią instrukcję, aby program odpowiednio skreślał liczby. Skompiluj i uruchom, by przetestować. Następnie uruchom go jeszcze raz tak:

`$ ./a.out > wynik.txt`

Spowoduje to, że rezultat działania programu nie zostanie wypisany na ekran, tylko zapisany do pliku o nazwie wynik.txt (przekierowanie wyjścia). Następnie ściągnij plik primes.txt, zawierający poprawne rozwiązanie tego zadania. Użyj programu diff do sprawdzenia, czy są różnice pomiędzy Twoim wynikiem, a prawidłowym:

`$ diff primes.txt wynik.txt`

Jeśli program diff **nic** nie wypisze, to znaczy, że oba pliki są identyczne, co oznacza poprawnie napisany algorytm.

2. Zwróć uwagę na wykorzystanie dyrektywy preprocesora `#DEFINE` do tworzenia własnych stałych w programie. Zmień wartości liczbowe stałych na inne, sprawdź, czy program działa tak samo. Pamiętaj, że wartości stałych muszą się mieścić w zakresie typu char, czyli od -128 do 127. Można oczywiście zadeklarować tablicę większego typu niż char, ale wówczas jest to niepotrzebne marnowanie pamięci, gdy praktycznie potrzebne są tylko 2 wartości.
3. Ustaw wartości stałych na tą samą liczbę - jak teraz zachowuje się program? Czy potrafisz wyjaśnić dlaczego?

### **Ćwiczenie 3**

W poprzednim zadaniu pojawiło się przekierowanie wyjścia. Analogicznie możliwe jest przekierowanie wejścia, jak np:

`$ s./a.out < wejscie.txt`

W powyższym przypadku treść pliku wejście.txt zostanie podana do programu tak, jakby była wpisana z klawiatury.

Pliki [we3a.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/we3a.txt) i [we3b.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/we3b.txt) mają następujący format:

1. Na początku znajduje się liczba całkowita m podająca ile znajduje się za nią liczb.
2. Następnie jest m liczb całkowitych dodatnich.

Napisz program, który:

* utworzy tablicę wielkości m
* wczyta liczby do tej tablicy
* ustali wartość największej i najmniejszej liczby w tablicy
* narysuje dla całej tablicy wykres słupkowy z gwiazdek, ale dla najmniejszej i największej słupki odpowiednio z minusów i plusów

Poniżej prawidłowe rozwiązanie ćwiczenia:

`$ ./a.out < we3a.txt`

    Najmniejsza: 1, największa: 10

    -
    **
    ***
    ****
    *****
    ******
    *******
    ********
    *********
    ++++++++++

`$ ./a.out < we3b.txt`

    Najmniejsza: 3, największa: 20

    *****************
    ++++++++++++++++++++
    ---
    **************
    ---
    ****
    ***********
    ****
    *****
    ****
    ******
    *******************
    ---
    *******
    *************
    ********
    ***************
    *****************
    *********
    *******************
    ++++++++++++++++++++
    **********
    ***********
    ************

### **Ćwiczenie 4**

Plik [cw4.c](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/cw4.c) zawiera niekompletny program do dokończenia. Struktura plików [we4a.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/we4a.txt), [we4b.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/we4b.txt) i [we4c.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/we4c.txt) jest następująca:

* Na początku znajduje się liczba całkowita `m` a następnie `m` liczb zmiennoprzecinkowych. Są one wczytywane przez program do tablicy A.
* Następnie znajdują się zestawy zadań, złożone z jednej, dwóch lub trzech liczb w układzie numer operacji i maksymalnie dwie liczby dodatkowe. Dla odpowiedniej czytelności, w plikach wejściowych każde zadanie jest w osobnej linijce.
* Operacja o numerze `0` (zero) oznacza koniec listy zadań. Program jest tak napisany, żeby w tym momencie zakończyć działanie, uprzednio wyświetlając komunikat `KONIEC`. Operacja ta nie ma żadnej liczby dodatkowej.
* Operacje o numerach `1`, `2`, `3` są to operacje dwuargumentowe. Dwie dodatkowe liczby oznaczają numery komórek tablicy A stanowiące argumenty operacji, czyli np. `1 5 6` oznacza `A[5]` + `A[6]`
* Operacje o numerach `10`, `11` są to operacje jednoargumentowe. Jedna dodatkowa liczba oznacza numer komórki tablicy A czyli np. `10 5` oznacza `sin(A[5])`.

Funkcja `operacja()` została tak napisana, żeby wykonywała odpowiednią operację. Ona nie wymaga żadnych poprawek. Należy jednak tak uzupełnić funkcję `main()`, żeby funkcja `operacja()` była odpowiednio wywoływana:

1. Na podstawie numeru operacji ustal, czy ona jest jedno czy dwuargumentowa i wczytaj odpowiednią liczbę argumentów. (Przypadek operacji nr 0 czyli koniec, został już napisany.)
2. Argumenty mogą celowo podawać numer komórki nie istniejący w tablicy. Sprawdź każdy z argumentów, czy jest w zakresie od 0 do m-1 włącznie. Jeśli któryś z nich nie jest, nie wykonuj tego zadania, przejdź do następnego np. z użyciem słowa continue.
3. Funkcję `operacja()` należy wywołać z odpowiednimi wartościami wziętymi z tablicy A, a wynik wypisać na ekran.

Prawidłowe odpowiedzi do ćwiczenia znajdują się w plikach [rez4a.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/rez4a.txt), [rez4b.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/rez4b.txt) i [rez4c.txt](https://github.com/anna-wro/epi.c/blob/master/05.%20tablice%2C%20instrukcja%20switch%20i%20przekierowania/rez4c.txt) odpowiednio. Możesz użyć polecenia diff do stwierdzenia poprawności działania Twojego programu.

**Uwaga**, program używa funkcji matematycznych z pliku math.h. Należy przy kompilacji użyć przełącznika -lm, jak tu:

    gcc -lm cw4.c
    
w przeciwnym przypadku linker (ld) zgłosi błąd nieodnalezienia odpowiednich funkcji.
