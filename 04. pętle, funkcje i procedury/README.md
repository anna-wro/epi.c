O tworzeniu własnych funkcji w podręczniku Wikibooks.
Ćwiczenie 1:

Plik cw1.c zawiera niekompletny program, który ma za zadanie wypisać tylko liczby pierwsze z zakresu od 2 do 1000. Służy do tego pętla w funkcji main(), która wywołuje funkcję ile_dzielnikow(), aby ta obliczyła, ile dana liczba ma dzielników. Na razie funkcja ile_dzielnikow() twierdzi, że każda liczba ma 2 dzielniki. Należy uzupełnić ją kodem, który będzie obliczał prawdziwą liczbę dzielników liczby podanej jako argument. Skorzystaj ze swojego kodu z ćwiczenia 5 z poprzedniego zestawu.

Ćwiczenie 2:

Silnia jest to funkcja matematyczna definiowana wzorem: n! = 1*2*3*...*n. Napisz program obliczający za pomocą pętli silnię danej liczby podanej na wejście. Pomocny może tu być operator *= który działa tak, że a *= b oznacza a = a * b, czyli pomnóż a przez b i wynik zapisz do a.
Napisz teraz alternatywną implementację, ktora obliczy silnię na zasadzie n! = n*(n-1)*...*2*1
Napisz funkcję int silnia(int n) ktora oblicza silnię przez wywołanie samej siebie według nastepującego schematu:
silnia(n) = n*silnia(n-1)
silnia(1) = 1
silnia(0) = 1
Ćwiczenie 3:

Plik cw3.c zawiera program wykorzystujący pętlę w pętli do wypisania na ekran kwadratu z gwiazdek. Dodaj do kodu warunek, który zastąpi gwiazdke spacją tak, aby uzyskać nastepujące rezultaty:

$ ./a.out
       *
      **
     ***
    ****
   *****
  ******
 *******
********
$ ./a.out
*       
**      
***     
****    
*****   
******  
******* 
********
$ ./a.out
********
 *******
  ******
   *****
    ****
     ***
      **
       *
$ ./a.out
********
******* 
******  
*****   
****    
***     
**      
*       
$ ./a.out
* * * * 
 * * * *
* * * * 
 * * * *
* * * * 
 * * * *
* * * * 
 * * * *
$ ./a.out
**      
***     
 ***    
  ***   
   ***  
    *** 
     ***
      **
$ ./a.out
********
*      *
*      *
*      *
*      *
*      *
*      *
********
Ćwiczenie 4:

Napisz program, wypisujący na ekran tabliczkę mnożenia jak na poniższym przykładzie. Zastosuj w printf() znak tabulacji \t, aby uzyskać rozmieszczenie liczb w równych kolumnach.

$ ./a.out
*	1	2	3	4	5	6	7	8	9
1	1	2	3	4	5	6	7	8	9
2	2	4	6	8	10	12	14	16	18
3	3	6	9	12	15	18	21	24	27
4	4	8	12	16	20	24	28	32	36
5	5	10	15	20	25	30	35	40	45
6	6	12	18	24	30	36	42	48	54
7	7	14	21	28	35	42	49	56	63
8	8	16	24	32	40	48	56	64	72
9	9	18	27	36	45	54	63	72	81
Ćwiczenie 5:

Procedura jest to struktura programu podobna do funkcji, ale nie zwracająca żadnej wartości, ponieważ wykonuje innego typu czynność niż obliczanie wyniku. Procedurę tworzy się tak samo jak funkcję, ale używa się słowa void (ang. pusty) przed jej nazwą.

Napisz program, który zawiera procedurę void rysuj(int rozmiar) która w zaleznosci od wartości argumentu rozmiar rysuje na ekranie wzorek:

1:

*
2:

 * 
***
 *
3:

  *  
 *** 
*****
 *** 
  *  
(...)
6:

     *     
    ***    
   *****   
  *******  
 ********* 
***********
 ********* 
  *******  
   *****   
    ***    
     *     
itd.
Dopisz odpowiednią funkcję main(), która pobiera od użytkownika jedną liczbę całkowitą i wywołuje procedurę rysuj() z tą liczbą.
