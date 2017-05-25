# Typy danych, zmienne i operatory

### **Ćwiczenie 1**

1. Zapoznaj się z programem zad1.c, skompiluj go i uruchom.

2. Język C oferuje następujące podstawowe typy danych:

  * liczby całkowite: `char`, `short`, `int`, `long`, `long long` - mogą reprezentować zakres liczb od -2<sup>n-1</sup> do 2<sup>n-1</sup>-1
  
  * liczby bez znaku: `unsigned char`, `unsigned short`, `unsigned int`, `unsigned long`, `unsigned long long` - zakres od 0 do 2<sup>n</sup>-1 
  * liczby zmiennoprzecinkowe: `float`, `double`, `long double` - obejmują wybrany podzbiór liczb wymiernych
  
     gdzie w powyższym n - liczba bitów. Wzorując się na zad1.c, napisz własny program, w którym utwórz po 1 zmiennej każdego z ww. typów i sprawdź za pomocą operatora **sizeof** jej długość (w bajtach). Następnie, używając kalkulatora lub suwaka logarytmicznego oblicz, jakie zakresy liczb poszczególne typy mogą reprezentować (**1 bajt = 8 bitów**).  
3. Zapoznaj się z dokumentacją funkcji [printf()](http://www.cplusplus.com/reference/cstdio/printf/). Jest tam opisany sposób tworzenia kodów formatujących dla poszczególnych typów danych (wyrażenia zaczynające się od znaku %). Rozbuduj swój program z poprzedniego punktu tak, że każdej utworzonej zmiennej nadaj jakąś wartość, a następnie wypisz tą wartość na ekran za pomocą printf(). Zrób tak, że wartości wszystkich tych zmiennych były wypisane przez pojedyncze wywołanie funkcji printf().

### **Ćwiczenie 2**

1. Zapoznaj się z programem zad2.c, skompiluj go i uruchom.
2. Dopisz do programu wykonanie następujących działań: * (mnożenie), / (dzielenie), % (modulo). Skompiluj i przetestuj z następującymi danymi:

   * Wprowadź dwie liczby całkowite, różne od 0 i od siebie.
   * Wprowadź liczbę dodatnią i ujemną.
   * Wprowadź dwa razy tą samą liczbę.
   * Jako liczbę b wprowadź zero. Co się dzieje w trakcie działania programu? W której linijce działanie programu zostaje przerwane i dlaczego?
   * Spróbuj wprowadzić liczby ułamkowe - jak reaguje na nie scanf()?
   * Wprowadź dwie liczby takie, żeby ich suma lub iloczyn przekroczyły zakres reprezentacji dla typu int.


### **Ćwiczenie 3**

1. Poleceniem

        cp zad2.c zad3.c
       
   skopiuj plik. W tym ćwiczeniu pracuj na zad3.c.
   
2. Zwróć uwagę, że funkcja printf() bierze *wartość* zmiennej, natomiast scanf() bierze *adres* zmiennej. Różnica w tym, jak podać funkcji wartość, a jak adres zmiennej, widoczna jest w kodzie.
3. W pliku zad3.c zmień typ zmiennych z `int` na `double`. Na podstawie dokumentacji funkcji [scanf()](http://www.cplusplus.com/reference/cstdio/scanf/) i printf() podmień kody formatujące w wywołaniach scanf() i printf() tak, żeby prawidłowo obsługiwały zmienne typu `double`.
4. Spróbuj skompilować. Czy udało się? Usuń linijkę z wywołaniem operatora, który nie występuje dla typu `double`. Skompiluj ponownie.
5. Przetestuj na następujących danych:
  *. Wprowadź dwie liczby całkowite, różne od 0 i od siebie. Jak zmienił się wynik dzielenia?
  * Wprowadź dwie liczby ułamkowe. Czy scanf() reaguje teraz prawidłowo i czy wynik jest dobry?
  * Jako liczbę b wprowadź zero. Jak teraz program się zachowuje?

### **Ćwiczenie 4**

Zapoznaj się z programem zad4.c. Skompiluj i przetestuj używając różnych danych wejściowych, aby przekonać się, jak działa automatyczna (czyli niejawna) konwersja typów. Wprowadź także takie dane, które spowodują przepełnienie typów `int`, `short` i `char`.
