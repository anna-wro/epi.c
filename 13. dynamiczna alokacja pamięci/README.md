# Dynamiczna alokacja pamięci

Wszystkie zmienne posiadające własną nazwę, np.:

    int x;
    char T[50];
    double * p;
są tworzone przy kompilacji programu i istnieją w takiej postaci przez cały czas działania programu. W niektórych zastosowaniach to wystarcza, ale w programach rozwiązujących bardziej skomplikowane problemy może być tak, że ilość potrzebnej pamięci da się ustalić dopiero po uruchomieniu programu, w dodatku będzie to różna ilość w zależności od tego, na jakich danych program uruchomiono.

Najprostszym takim problemem jest wczytanie pliku z dysku do pamięci programu. Plik jest ciągiem bajtów, w języku C odpowiada mu typ char (ewentualnie unsigned char). Możemy utworzyć tablicę tego typu, ale nie jesteśmy w stanie wiedzieć przy kompilacji, jakiej wielkości: pliki tekstowe mogą mieć wielkość rzędu np. kilobajtów, obrazy rzędu megabajtów a nagrania video nawet i gigabajtów.

Ponadto na zajęciach ASD zapoznają się Państwo z rozmaitymi złożonymi strukturami danych, jak listy, drzewa, grafy i inne. Kształt takiej struktury też często będzie zależał od rozwiązywanego problemu i dynamiczna alokacja będzie niezbędna, żeby odpowiednią taką strukturę utworzyć.

### malloc

W języku C pamięć dynamicznie tworzy się funkcją malloc() (#include <stdlib.h>), jak np.:

    void * m = malloc(100);
Powyższy kod powoduje zajęcie w pamięci bloku wielkości 100 bajtów i zapisanie adresu tego bloku do wskaźnika o pseudotypie void. W normalnym użyciu bardziej przydatne byłoby zapisanie adresu do wskaźnika jakiegoś konkretnego typu, jak np.:

    char * c = malloc(100);
W tym przypadku dostaliśmy tablicę typu jednobajtowego char, o prawidłowym zakresie c[0] do c[99].

    short * d = malloc(100);
W tym przypadku dostaliśmy tablicę typu dwubajtowego short, więc prawidłowy zakres to d[0] do d[49].

    int * f = malloc(100);
Przy czterobajtowym typie int zakres prawidłowy to oczywiście f[0] (zajmuje bajty 0 do 3) do f[24] (zajmuje bajty 96 do 99).

    double * g = malloc(100);
Przy ośmiobajtowym typie double tablica mieści... 12,5 liczby! Oczywiście użytecznych będzie tylko 12 komórek od g[0] do g[11], ostatnie 4 bajty się zmarnują: nie można zapisać pod g[12], bo połowa tej liczby wyjdzie poza zaalokowany obszar i spowoduje kłopoty.

W praktyce funkcję malloc() wywołuje się najczęściej w taki sposób:

    int * a = malloc(600 * sizeof(int));
w ten sposób zaalokowaliśmy tablicę na 600 int-ów, bez konieczności pamiętania, ile bajtów ma int.

### realloc

Jeśli w trakcie pracy z programem trzeba zwiększyć rozmiar danego bloku, służy do tego funkcja realloc():

    void * p = malloc(100);
    
    //eee... za mało!
    
    p = realloc(p, 200);
Blok o początkowej wielkości 100 bajtów został powiększony do 200 bajtów. Ważne: realloc może przenieść blok w inne miejsce pamięci, jeśli w danym miejscu nie ma wolnej przestrzeni na jego powiększenie. Powoduje to, że wszystkie wskaźniki pokazujące na ten blok przestaną być aktualne, bo znalazł się on gdzie indziej. Prawidłowy jest jedynie ten wskaźnik, który zwróciła funkcja realloc. Proszę pamiętać, aby po skorzystaniu z realloc-a zawsze zaktualizować wszystkie wskaźniki, którymi Państwo pracują na tym bloku.

Funkcją realloc można też zmniejszać rozmiar bloku, wówczas raczej nie nastąpi jego przeniesienie w inne miejsce pamięci.

### free

Zaalokowaną pamięć trzeba zwolnić po skończeniu pracy, służy do tego funkcja free():

    void * p = malloc(100);
    
    //coś robię z tym blokiem
    
    free(p);
    
Aby funkcja free() zadziałała, trzeba podać jej adres początku bloku, zwrócony przez malloc(), calloc() lub realloc(). Z tego powodu nie wolno "zgubić" tego adresu - zawsze przynajmniej jeden wskaźnik powinien trzymać ten adres od alokacji aż do zwolnienia.

### wycieki pamięci i inne zagrożenia

Wyciekiem pamięci nazywamy sytuację, kiedy zaalokowana pamięć nie została zwolniona, ponieważ zgubił się wskaźnik lub programista zwyczajnie zapomniał użyć free(). Jeśli taka pamięć używana jest do końca działania programu, to nie problem - po zakończeniu programu system operacyjny i tak wszystko posprząta: zwolni pamięć, pozamyka otwarte pliki itd. Gorzej jeśli mamy np. taką pętlę:

    int i;
    void * p;
    for(i = 0; i < 1000000; ++i)
    {
        p = malloc(1000);

        //coś robimy z p

        //ale nie zwalniamy
    }

w każdej iteracji wskaźnik p zostaje nadpisany adresem nowego bloku o rozmiarze 1000 bajtów, a poprzednio używany blok staje się niedostępny, bo nie mamy już jego adresu. Po wykonaniu miliona iteracji mamy 1 gigabajt zaalokowanej, a niedostępnej do użytku pamięci!

Podsumowując, zagrożenia związane z użyciem dynamicznej alokacji pamięci są następujące:

Funkcja realloc() może (ale nie musi) przesunąć blok w inne miejsce pamięci i wszystkie wskaźniki używane do pracy na tym bloku stają się nieaktualne. Należy pamiętać o ich aktualizacji za pomocą wskaźnika zwróconego przez realloc().
Trzeba pamiętać, żeby zwalniać pamięć gdy tylko stanie się niepotrzebna. Pomyłki zdarzają się często, gdy programista korzysta z funkcji, która w ramach swojego działania alokuje pamięć na wynik (i zwraca do niej wskaźnik), a programista nie jest świadomy, że powinien sam tą pamięć zwolnić.
Oferowana przez język C niezautomatyzowana obsługa dynamicznej alokacji pamięci wymaga od programisty uwagi i staranności w jej używaniu. Inne języki albo oferują możliwość zautomatyzowania tej obsłuji (jak np. C++), albo taką automatyzację narzucają (jak np. Java albo C#).

### Ćwiczenie 1

Narzędzie valgrind może służyć do wykrywania wycieków pamięci. Jest to maszyna wirtualna, która uruchamia w sobie program i obserwuje jak się zachowuje. Kto używa dynamicznej alokacji pamięci, powinien zawsze testować swój program narzędziami typu valgrind.

Niestety, valgrind nie jest dostępny na komputerach w pracowni, ale jest dostępny na wierzbie.

Używając SSH zaloguj się do swojego konta na wierzbie.
Za pomocą np. mcedit, napisz prosty program, który używa malloc(), ale nie używa free(). Skompiluj.
Uruchom program (./a.out) wewnątrz valgrinda poleceniem: $ valgrind --leak-check=yes ./a.out
Teraz dopisz do programu odpowiednie wywołanie free(), skompiluj i uruchom w valgrindzie jeszcze raz. Porównaj uzyskane komunikaty.

### Ćwiczenie 2

Wczytaj plik tekstowy do pamięci, do uprzednio zaalokowanego bloku o takiej samej wielkości co plik.

Aby dowiedzieć się, jaka jest wielkość pliku, najprościej użyć kursor:

FILE * fp = fopen("mój_plik","r"); //na platformie Windows "rb"

fseek(fp, 0, SEEK_END); // przesunięcie kursora na koniec pliku

int r = ftell(fp); // odczytanie aktualnej pozycji kursora

fseek(fp, 0, SEEK_SET); // przesunięcie kursora na początek pliku
W ten sposób w zmiennej r powinna znajdować się liczba bajtów pliku, którą można użyć jako argument dla malloc. Sam plik powinien być trzymany w tablicy typu char lub unsigned char, a przekopiowanie pliku do tablicy można zrobić w jednym wywołaniu funkcji fread().

### Ćwiczenie 3

Lista jest to taka struktura danych, w której każdy element składa się z pewnej wartości (jak komórka tablicy) oraz wskaźnika na następny element. Na końcu listy, gdy następnego elementu już nie ma, wskaźnik ten jest zwykle ustawiony na zero, co oznacza koniec listy.

Artykuł na Wikipedii o liście - dla tego zadania istotna jest jedynie lista jednokierunkowa.

Z listy korzysta się bardzo wygodnie w połączeniu z dynamiczną alokacją. Jeśli chcemy dodać nowy element na koniec listy, wystarczy utworzyć ten element za pomocą malloc(), a następnie wskaźnik do niego zapisać jako wskaźnik w dotychczasowym ostatnim elemencie.

Utwórz listę jednokierunkową, której pojedynczy element oprócz wskaźnika do następnego pola zawiera jeszcze dwie zmienne int: liczbę i jej ilość. Dany jest plik zawierający sekwencję losowych, powtarzających się liczb. Otwórz ten plik w programie, następnie przeczytaj go z użyciem fscanf(). Dla każdej odczytanej tak liczby przejdź całą listę: jeśli taka liczba już jest na liście, zwiększ jej pole ilość o 1, jeśli nie ma, dodaj nowy element, reprezentujący tą liczbę, na końcu. Gdy przeczytasz cały plik - wyświetl zawartość uzyskanej listy: jakie liczby występują i ile razy się powtarzają.

Niezbędny do zadania plik z liczbami utwórz we własnym zakresie. Przynajmniej niektóre liczby powinny się powtarzać.

Dodatkowe zadanie "z gwiazdką": utwórz listę w porządku rosnącym liczb: nowy element dodawaj nie na końcu, ale w środku, na właściwej dla niego pozycji w sensie porządku rosnącego.
