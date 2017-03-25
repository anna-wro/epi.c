Instrukcje sterujące (if, for i inne) w podręczniku Wikibooks.
Ćwiczenie 1:

Program cw1.c demonstruje użycie instrukcji warunkowej if/else. Zapoznaj się z treścią i spróbuj przewidzieć:

gdy wejściem będzie liczba dodatnia, pojawią się komunikaty numer: ......
gdy wejściem będzie liczba ujemna, pojawią się komunikaty numer: ......
gdy wejściem będzie zero, pojawią się komunikaty numer: ......
Teraz skompiluj i przetestuj, czy przewidywania okazały się prawidłowe.
Ćwiczenie 2:

W pliku cw2.c znajduje się niekompletny program, który ma przyjąć od użytkownika dwie liczby, a następnie powiedzieć, czy jedna dzieli się przez drugą. Uzupełnij program, aby działał jak poniżej:
$ ./a.out
Podaj dzielną:  9
Podaj dzielnik: 3

Liczba 9 dzieli się przez 3.
$ ./a.out
Podaj dzielną:  5
Podaj dzielnik: 3

Reszta z dzielenia 5 przez 3 to 2.
$
Skompiluj i przetestuj działanie programu.
Wprowadź jako dzielnik liczbę 0. Jak widać, program zostaje przerwany sygnałem błędu. Dodaj do programu taki warunek, żeby w takim przypadku zamiast komunikatu o błędzie wyświetliła się informacja:
$ ./a.out
Podaj dzielną:  1
Podaj dzielnik: 0

Dzielenie przez 0 niewykonalne.
$
Ćwiczenie 3:

W pliku cw3.c znajduje się prosty przykład pętli. Zapoznaj się z treścią. O zmiennej i mówimy, że jest licznikiem pętli. Skompiluj i uruchom.
Zrób kopię pliku cw3.c. Zmodyfikuj teraz wartość początkową licznika i warunek pętli tak, żeby pojawiły się liczby od 3 do 20. Skompiluj i uruchom.
Zrób kopię pliku cw3.c. Wyrażenie ++i oznacza zwiększ i o 1. To ono powoduje, że licznik pętli za każdym razem się zwiększa. Zamiast ++i można napisać i++ albo i += 1 albo i = i + 1. Wypróbuj te możliwości. Następnie, przetestuj kod, w którym licznik pętli zwiększa się o 2, o 3, o 4 itd.
Zrób kopię pliku cw3.c. Wyrażenie --i będzie zmniejszać i o jeden. Zastanów się, jaką wartość początkową i warunek pętli należy ustanowić, aby wypisać liczby od 15 do 0 (włącznie)? Skompiluj i przetestuj.
Ćwiczenie 4:

Zrób kopię pliku cw3.c. Umieść wewnątrz pętli warunek, żeby liczba była wypisana tylko, jeśli jest nieparzysta.
Zrób kopię pliku cw3.c. Zmień zakres liczb na od 11 do 99, ale po liczbach 20, 30, 40 ... 90 wypisz znak nowej linii - symbol \n w printf().
Ćwiczenie 5:

Napisz program, który przyjmie od użytkownika 1 liczbę całkowitą i w odpowiedzi poda, czy jest liczbą pierwszą, a jesli nie, to ile ma dzielników. Użyj pętli, by sprawdzić, które liczby są dzielnikami liczby podanej przez użytkownika. Użyj wyrażenia ++ by zliczać dzielniki.
