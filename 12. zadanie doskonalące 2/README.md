# Zadanie doskonalące 2

Obowiązkowy zakres materiału na laboratorium Wprowadzenie do Programowania został zrealizowany. Celem tego zestawu jest doskonalenie umiejętności programowania w języku C i korzystania z jego biblioteki standardowej.

Aby otrzymać 1 punkt liczony do podstawowej sumy punktów, należy rozwiązać zadanie w pracowni i przedstawić prowadzącemu do oceny. W tym zestawie nie ma możliwości oddania raportu.

Istnieje możliwość uzyskania 1 punktu dodatkowego, dodającego się do sumy punktów z semestru, ale bez zwiększania mianownika. Aby go uzyskać, należy rozwiązać zadanie dodatkowe
Zadanie podstawowe

Używamy pliku zenum.txt znanego z porzedniego zestawu zadań. Znajduje się w nim baza danych pracowników pewnej firmy. Poszczególne kolumny, oddzielone spacją, oznaczają: imię, nazwisko, identyfikator wydziału, pensję miesięczną, liczbę nadgodzin w roku. Utwórz strukturę odpowiadającą pojedynczej osobie: dla pól imię i nazwisko przyjmij typ char[50], wydział jako pojedynczy znak, pensję jako int i liczbę nadgodzin jako short.

W tym zadaniu zakładamy, że nie wiemy z góry, ile jest osób opisanych w tej bazie. Aby wczytać plik do tablicy, trzeba skorzystać z dynamicznej alokacji. Na początek zaalokuj tablicę na 10 osób. Jeśli po wypełnieniu 10 miejsc jeszcze są kolejne linijki w pliku, użyj realloc(), aby zwiększyć rozmiar do 20 osób, później w razie potrzeby do 30, 40 itd. Pamiętaj, że realloc może przesunąć tablicę w inne miejsce w pamięci, dlatego zawsze używaj wskaźnika zwróconego przez realloc.

Do wczytywania danych pojedynczej osoby najwygodniej użyć funkcji fscanf, z uwagi na to, że ona kończy czytanie na najbliższym białym znaku. W tym przypadku jej użycie jest bezpieczne, ponieważ z założenia ani imię ani nazwisko nie będzie mieć 50 znaków.

Do wczytania identyfikatora wydziału można użyć fscanf lub fgetc, przy czym trzeba pamiętać, że pierwszym przeczytanym znakiem będzie spacja przed właściwym znakiem.

Po wczytaniu wypisz wszystkich pracowników na ekran.

Wskazówka: ponieważ liczba pracowników (230) przekracza liczbę linii na ekranie, dla wygody uruchamiaj program z przekierowanym wyjściem, np. $ ./a.out > wynik.txt W ten sposób rezultat działania zostanie zapisany do pliku o nazwie wynik.txt.

Zadanie dodatkowe

Zakładamy, że nie wiemy z góry, ile jest działów (identyfikowanych literami) w przedsiębiorstwie. Utwórz listę jednokierunkową (omówiona w zestawie 10 zad. 3), która będzie przechowywać identyfikatory wydziałów. Dla każdej osoby, sprawdź czy jej identyfikator wydziału jest na liście, jeśli nie, to dopisz na końcu listy.

Mając już listę wszystkich wydziałów, wypisz na ekran: identyfikator wydziału i sumę nadgodzin pracowników tego wydziału.
