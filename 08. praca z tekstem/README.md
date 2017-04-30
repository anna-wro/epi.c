
Ćwiczenie 1:

Zmienne tekstowe, zwane napisami lub z języka angielskiego - stringami w języku C realizowane są za pomocą tablic typu char zakończonych znakiem zero ('\0') oznaczającym koniec danego napisu. Znak zero informuje, że obojętnie ile więcej miejsca jest w tablicy, dany napis kończy się w tym miejscu. Wszystkie funkcje biblioteki C mające do czynienia ze stringami respektują tą konwencję.

Poniższe deklaracje powinny być identyczne:

char napis1[] = {'W', 'i', 't', 'a', 'j', '\0'};
char napis2[] = "Witaj";
Napisz program wykorzystujący funkcję strcmp (#include <string.h>) do stwierdzenia, czy tak właśnie jest.

Zauważ, że wartości typu char podaje się w cudzysłowach pojedynczych, np. 'a', '\n', natomiast cudzysłowy podwójne automatycznie tworzą tablicę char, jednocześnie dodając na końcu znak zero.

Uwaga! Ze względu na to, że konsola w komputerach w pracowni używa formatu UTF-8, polskie znaki ąćęłńśóźż kodowane są dwubajtowo, czyli zajmują dwa znaki według rachunku char. Z tego powodu np. popularny pangram Zażółć gęślą jaźń produkuje na ekranie 17 znaków, choć zajmuje pamięci na 26. Proszę mieć to na uwadze rozwiązując poniższe ćwiczenia, a także to, że taki dwuznakowy znak przekrojony na pół nie będzie wyświetlał się prawidłowo.
Ćwiczenie 2:

Aby wczytać tekst od użytkownika, najlepiej użyć funkcji fgets, jak na przykładzie:

char bufor[100];
fgets(bufor,100,stdin);
Funkcja fgets będzie czytać znaki z wejścia do momentu natrafienia na znak '\n' (naciśnięcie klawisza Enter), albo do momentu osiągnięcia maksymalnej liczby znaków (w przykładzie 100). Pamiętaj, aby nie przepełnić tablicy, dlatego zawsze podawaj jako drugi argument liczbę nie większą niż faktyczny rozmiar tablicy. Zmienna stdin oznacza standardowe wejście, czyli klawiaturę.

Wypisanie napisu na ekran najprościej zrobić tak:

printf("%s",bufor);
Napisz program, który poprosi użytkownika o wprowadzenie imienia, np. Adam, a następnie wyświetli Cześć Adam.

Napisy można modyfikować, odwołując się do poszczególnych znaków jak do elementów tablicy. Zmodyfikuj program tak, że po wczytaniu imienia, zmień pierwszą literę na 'X', a następnie wyświetl napis na ekranie. Następnie zmodyfikuj tak, że zmień dziesiątą literę na znak '\0'. Jak zachowa się printf przy wypisywaniu? Przetestuj dla napisu krótszego od i dłuższego niż 10 znaków.

Ćwiczenie 3:

Funkcja strlen służy do określania ile znaków ma dany napis, czyli dokładnie na której pozycji znajduje się pierwszy znak '\0'.

Napisz program, który wczyta tekst od użytkownika i wyświetli, ile on ma znaków, następnie napisz własną funkcję działającą tak jak strlen: w pętli zliczaj znaki aż natrafisz na znak zero (jego nie licz). Przetestuj, czy Twoja funkcja działa tak samo jak strlen.

Napisz teraz funkcję postaci int ile(char * tekst, char znak), która policzy ile razy dany znak występuje w tekscie, tzn. np. dla wywołania ile("Ala ma kota",'a') funkcja powinna zwrócić wartość 3.

Ćwiczenie 4:

Funkcja strcpy służy do kopiowania napisu do innej zmiennej. Napisz program, który przetestuje jej działanie. Pamiętaj, że zmienna docelowa musi być tablicą nie mniejszą niż rozmiar kopiowanego tekstu.

Napisz własną funkcję działającą na zasadzie strcpy, ale odwracającą tekst przy kopiowaniu, czyli np. "Witaj!" w nowej zmiennej będzie "!jatiW".

Przy kodowaniu UTF-8, funkcja przepisująca znak po znaku nie odwróci poprawnie znaków dwu- lub wiecej -bajtowych. Jest to normalne zjawisko. Przetestuj je na przykładzie napisów zawierających polskie znaki. Aby poprawnie odwracać napisy zawierające znaki wielobajtowe, należałoby skorzystać z biblioteki z pełną obsługą Unikodu, jak np. ICU. Nie jest to obowiązkowe na zajęciach z WdP.
Ewentualnie, można skorzystać z funkcji utf8chlen() dostępnej w tym pliku. Oblicza ona długość sekwencji reprezentującej jeden znak, a kod w main() demostruje jej zastosowanie.

Ćwiczenie 5:

Funkcja strcat realizuje konkatenację (łączenie) napisów. Napisz program, który zapyta użytkownika o imię, wczyta do jednej zmiennej, następnie zapyta o nazwisko, wczyta do drugiej zmiennej, w trzeciej zmiennej połączy imię z nazwiskiem (ze spacją pomiędzy) i tak wyświetli na ekranie.

Ćwiczenie 6:

Napisz program, który sprawdzi, czy wprowadzone słowo jest palindromem np. "abababacdcabababa".
