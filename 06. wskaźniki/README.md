Ćwiczenie 1:

Plik cw1.c demonstruje użycie wskaźników.

Analizę pliku rozpocznij od funkcji main() i użytego w niej wskaźnika p.
Następnie przyjrzyj się, w jaki sposób funkcja zeruj() jest zdolna, żeby zmienić wartość zmiennej, która do niej nie należy.
Teraz zastanów się, co trzeba zmienić w funkcji zamien(), żeby ona była w stanie zamienić dwie zmienne ich wartościami, tzn. jeśli początkowo np. a = 1, b = 2, to po użyciu funkcji zamien() powinno być a = 2, b = 1.
Ćwiczenie 2:

Gdy rezultatem obliczeń w funkcji jest pojedyncza liczba, wtedy można ją łatwo przesłać jako wartość funkcji, za pomocą słowa return. Ale co zrobić, gdy rezultatem obliczeń jest więcej niż jedna liczba? Można wykorzystać wskaźniki do zwrócenia większej liczby wyników.

Plik cw2.c posiada funkcję rozwiązującą równania kwadratowe. Pojawia się tam problem różnej liczby wyników z jednej funkcji. Rozwiązaniem równania kwadratowego będzie zero, jedna lub dwie liczby. Funkcja kwadratowe pobiera dane typu zmiennoprzecinkowego (double) i zwraca rozwiązania równania również tego typu, poprzez wskaźniki x1 i x2, ale dodatkowo zwraca także wartość typu int, która informuje nas o tym, który przypadek zaistniał:

Jeśli a == 0.0 to nie jest to równanie kwadratowe. Funkcja sygnalizuje to wartością -1.
Jeśli Δ < 0, równanie nie ma rozwiązań. Funkcja sygnalizuje to wartością 0.
Jeśli Δ == 0, równanie ma 1 rozwiązanie. Funkcja zapisuje to rozwiązanie do zmiennej pod wskaźnikiem x1, a następnie kończy wartością 1.
Jeśli Δ > 0, równanie ma 2 rozwiązania. Funkcja zapisuje te rozwiązania do zmiennych pod wskaźnikami x1 oraz x2 i kończy wartością 2.
Uzupełnij program tak, aby funkcja main() wywoływała funkcję kwadratowe(), a następnie, w zależności od przypadku, wyświetlała na ekranie stosowny komunikat i wyniki.

Następnie dodaj do funkcji kwadratowe() zdolność obliczania punktu wierzchołkowego paraboli, za pomocą wzorów: p = -b/2a i q = -Δ/4a, zwróć ten punkt do main() w jakiś sposób i wyświetl go na ekranie razem z pozostałymi informacjami.

Ponieważ program potrzebuje funkcji sqrt() z biblioteki math.h, dlatego trzeba kompilować z przełącznikiem -lm. W przeciwnym razie dostaniemy błąd linkera - nieodnalezienia funkcji sqrt().
Ćwiczenie 3:

Wskaźniki mogą być wykorzystane do adresowania komórek tablic i w związku z tym oferują bardzo użyteczną arytmetykę wskaźników. Reguły są następujące:

Dla wskaźnika np.int * t, wyrażenie t+5 jest wskaźnikiem na wartość typu int pod adresem 5 długości int dalej niż t. Analogicznie, dla double * r wyrażenie r - 100 oznacza wskaźnik na wartość typu double pod adresem 100 długości double wcześniej niż r. Działają też operatory ++ i -- przesuwające wskaźnik na następny adres jego typu.
Dla wskaźników tego samego typu, np. short *p, *q, wyrażenie q - p oznacza liczbę, o ile odległości short jeden wskaźnik różni się od drugiego.
Wskaźniki można porównywać na ich adresy operatorami ==, <, >, <=, >=, !=.
W przypadku tablicy, np. int A[10]; symbol A jest jednocześnie wskaźnikiem na jej pierwszy element, tzn. np. *A oznacza A[0], a np. *(A+5) oznacza A[5]. Działa to też w drugą stronę, czyli &A[0] oznacza A, zaś &A[5] oznacza A+5.
Napisz funkcję, która obliczy średnią arytmetyczną z elementów w tablicy, mając za argumenty jedynie 2 wskaźniki: do pierwszego i ostatniego elementu tablicy. Tablica powinna być typu double, a funkcja postaci double srednia(double * poczatek, double * koniec).

Przykładowo, dla tablicy double A[20], wywołanie srednia(A,A+19) powinno dać wynik średniej dla całej tablicy, ale wywołanie srednia(A+3,A+5) powinno wyciągnąć średnią jedynie z komórek A[3], A[4], A[5]. Dzięki arytmetyce wskaźników, można w pętli iterować przy użyciu wskaźnika, tak jak przy użyciu liczby, np.
int A[10];
int * i;

for(i = A; i < A+10; ++i)
{
// *i to jest dostęp do elementu tablicy
}
jest równoważne
int A[10];
int i;

for(i = 0; i < 10; ++i)
{
// A[i] to jest dostęp do elementu tablicy
}
ewentualnie, wariant ze wskaźnikiem może być zapisany tak:
int A[10];
int * i;

for(i = &A[0]; i < &A[10]; ++i)
{
// *i to jest dostęp do elementu tablicy
}
Ćwiczenie 4:

Plik cw4.c zawiera pasjonującą, głęboką i wciągającą grę komputerową. Zdobywca głównego skarbu otrzymuje 8 trylionów punktow!

Po uruchomieniu gra wyświetla planszę o wymiarach 9x9. Pozycja gracza sygnalizowana jest literą G, natomiast pozycja skarbu literą S. Do poruszania się po planszy najwygodniejsza jest klawiatura numeryczna (Num Lock musi być włączony) - klawisze 8, 6, 2, 4 odpowiadają ruchom gracza na planszy (po każdej liczbie należy nacisnąć Enter). Gra kończy się po zdobyciu skarbu.

Mimo, że gra toczy się na dwuwymiarowej planszy 9x9, gra zaimplementowana jest tak, że używa jednowymiarowej tablicy o 81 komórkach. Zwróć uwagę w różnych miejscach kodu, jak dwuwymiarowa pozycja x,y przeliczana jest na jednowymiarowy indeks tablicy (z dodatkowym wykorzystaniem arytmetyki wskaźników).

Spróbuj rozbudować grę na następujące sposoby:

Dodaj graczowi możliwość wykonywania ruchów diagonalnych, tzn. "po skosie", czyli z równoczesną zmianą współrzędnej x i y. Najlepiej użyć do tego liczb odpowiednio 9, 3, 1, 7.
Dodaj zmienne globalne wysokość i szerokość. Zrób tak, żeby użytkownik na początku mógł wpisać wymiary planszy, na której chce grać. Popraw kod we wszystkich niezbędnych miejscach, żeby nie działał na ustalonej planszy 9x9, tylko na planszy o ustalonej przez użytkownika wysokości i szerokości.
Dodaj pająka P, który strzeże skarbu. Pająk, który będzie kontrolowany następującą formułą:
if(graczx < pajakx) pajakx--;
if(graczx > pajakx) pajakx++;
if(graczy < pajaky) pajaky--;
if(graczy > pajaky) pajaky++;
będzie zawsze szedł w kierunku gracza. W takim przypadku zdobycie skarbu będzie niemożliwe. Aby dać graczowi szansę, zrób tak, żeby pająk robił swój ruch co dwa ruchy gracza.
Alternatywnie, zamiast spowalniać pająka, gracz może mieć ze sobą muchę, którą poczęstuje pająka i zablokuje go tym na 3 ruchy, co powinno wystarczyć na to, by dotrzeć do skarbu.
Plik gra zawiera dla przykładu skompilowaną wersję gry z ruchami diagonalnymi, ustalaną szerokością i wysokością oraz pająkiem powolnym, ale bez muchy. Plik został skompilowany na wierzbie, ale działa na komputerach w pracowni (pod Linuksem). Studenci korzystający z Windowsa powinni przy użyciu SSH (np. PuTTy) zalogować się na swoje konto na wierzbie i tam uruchomić plik gra.

Uwaga, po ściągnięciu pliku gra do danego katalogu należy nadać temu plikowi uprawnienia do wykonania, co można zrobić poleceniem:
chmod u+x gra
