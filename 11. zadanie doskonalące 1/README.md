# Zadanie doskonalące 1

Obowiązkowy zakres materiału na laboratorium Wprowadzenie do Programowania został zrealizowany. Celem tego i następnego zestawu jest doskonalenie umiejętności programowania w języku C i korzystania z jego biblioteki standardowej.

Aby otrzymać 1 punkt liczony do podstawowej sumy punktów, należy rozwiązać zadanie w pracowni i przedstawić prowadzącemu do oceny. W tym zestawie nie ma możliwości oddania raportu.

Istnieje możliwość uzyskania 1 punktu dodatkowego, dodającego się do sumy punktów z semestru, ale bez zwiększania mianownika. Aby go uzyskać, należy rozwiązać zadanie dodatkowe
Operacje plikowe w niniejszym zadaniu należy wykonywać z właściwym wykorzystaniem funkcji bilbiotecznych, tzn.:

do pojedynczych znaków używać fgetc()
do napisów używać fgets() (do uprzednio przygotowanej tablicy)
do liczb (zapisanych dziesiętnie) używać fscanf()
Zapis może być wykonywany z użyciem fprintf() we wszystkich powyższych przypadkach, ewentualnie można użyć fputc() albo fputs().

sortowanie

Biblioteka standardowa C, konkretnie stdlib.h, zawiera funkcję sortującą qsort, wykorzystującą algorytm Quicksort autorstwa C.A.R. Hoare'a. Funkcja ta wygląda następująco:

void qsort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*))
base jest to wskaźnik do początku tablicy, która będzie posortowana. Jest typu void*, aby funkcja mogła sortować tablice dowolnego typu.

num jest liczbą elementów w tablicy.

size jest rozmiarem pojedynczego elementu w tej tablicy - konieczne, żeby funkcja wiedziała, gdzie kończy się jeden element, a zaczyna następny.

compar to wskaźnik do funkcji porównującej, która decyduje, który element jest mniejszy, a który większy. Z założenia ma zwrócić liczbę mniejszą od zera, jeśli pierwszy element jest mniejszy; większą od zera jeśli pierszy element jest większy; równą zero jeśli elementy są równe.

Przykładowo, jeśli mamy tablicę int-ów do posortowania rosnąco, trzeba to zrobić następująco:

int porownaj(int * a, int * b)
{
    return (*a - *b);
}
To jest nasza funkcja porównująca. Odejmowanie a - b załatwia sprawę co jest mniejsze, a co większe. Ewentualnie można by to zapisać tak:

int porownaj2(int * a, int * b)
{
    if(*a < *b) return -1;
    if(*a > *b) return 1;
    return 0;
}
Powyższe funkcje sortują w porządku rosnącym. Jeśli chcemy posortować w porządku malejącym, wystarczy odwrócić sens wyniku zwracanego przez funkcję: mniejsza ma być większą a większa mniejszą.

Mając już funkcję porównującą, możemy teraz uruchomić sortowanie w funkcji main(), lub innej, tak:

int T[100]; //utworzenie tablicy

//... uzupełniamy tablicę danymi

qsort(T, 100, sizeof(int), porownaj);
Jak widać z powyższego przykładu, nazwa funkcji jest jednocześnie wskaźnikiem do niej. Gdyby jednak ktoś potrzebował trzymać wskaźnik do takiej funkcji w zmiennej, deklaracja takiej zmiennej musiałaby być np. taka:

int (* p)(int *, int *) = porownaj;
gdzie p jest nazwą zadeklarowanej zmiennej. Jak widać, wskaźnik do funkcji w C/C++ musi zawierać w sobie typ funkcji i typ jej argumentów i nie ma "uniwersalnego" wskaźnika do wszystkich funkcji, takiego jak void * jest wskaźnikiem do każdej zmiennej.

Zadanie podstawowe

W pliku znajduje się baza danych pracowników pewnej firmy. Poszczególne kolumny, oddzielone spacją, oznaczają: imię, nazwisko, identyfikator wydziału, pensję miesięczną, liczbę nadgodzin w roku. Utwórz strukturę odpowiadającą pojedynczej osobie: dla pól imię i nazwisko przyjmij typ char[50], wydział jako pojedynczy znak, pensję jako int i liczbę nadgodzin jako short.

Utwórz tablicę typu takiego jak stworzona struktura o takiej wielkości, żeby pomieścić cały plik, następnie otwórz ten plik w programie i wczytaj go do tej tablicy, używając funkcji zgodnie z instrukcją na początku tego zestawu.

Napisz funkcję porównującą do posortowania tablicy rosnąco po nazwisku i imieniu: najpierw weź pod uwagę nazwiska, a jeśli są identyczne - sprawdź imiona. Aby ustalić który napis jest (alfabetycznie) większy, a który mniejszy, skorzystaj z dobrodziejstwa funkcji strcmp(). Uruchom qsort z tą funkcją i zademonstruj rezultat, wypisując dane pracowników na ekran.
Napisz funkcję porównującą do posortowania tablicy malejąco po liczbie nadgodzin. Posortuj i wypisz na ekranie wyłącznie tych pracowników, którzy mają więcej niż zero nadgodzin.
Zadanie dodatkowe

Utwórz uogólnione funkcje porównujące do sortowania rosnącego:

int porownaj_napisy(char ** a, char ** b) (wykorzystaj strcmp() dla wygody)
int porownaj_znaki(char * a, char * b)
int porownaj_short(short * a, short * b)
int porownaj_int(int * a, int * b)
Następnie napisz nadrzędną funkcję porównującą, która będzie sprawdzała pewną zmienną globalną w której będzie zapisany porządek sortowania. Jeśli ten porządek to będzie np. 12345, to funkcja najpierw będzie porównywać po pierwszej kolumnie (imię). Jeśli jest równość na imionach to patrzy na drugą kolumnę (nazwisko), jeśli tu jest równość to patrzy na trzecią kolumnę itd. Z tym, że taka funkcja musi wiedzieć wewnętrznie, że np. kolumna 1 - imię jest typu napis, żeby wywołać odpowiednią funkcję szczegółową z tych określonych powyżej.

Qsort-a należy wywołać na tej właśnie funkcji nadrzędnej (i oczekiwać od niej, że ona będzie wywoływać pozostałe funkcje w odpowiednim porządku i na odpowiednich danych). Oczywiście porządek sortowania trzeba podrzucić do tej funkcji przez jakąś zmienną globalną, np. typu char *, bo sama funkcja qsort nie oferuje możliwości "przepchnięcia" dodatkowego argumentu.

Po napisaniu uruchom program dla co najmniej dwóch różnych porządków sortowania.
