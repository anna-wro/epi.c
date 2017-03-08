#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, delta;

  printf(" Podaj wspolczynniki a, b, c: ");
  scanf("%lf %lf %lf", &a, &b, &c);
  if (a == 0)
    if (b == 0)
      if (c == 0)
        printf(" Rownanie nieoznaczone.\n");
      else
        printf(" Rownanie nie ma rozwiazania.\n");
    else
      printf(" Rownanie ma jedno rozwiazanie: %.2f\n", -c/b);
  else {
    delta = b*b - 4*a*c;
    if (delta < 0)
      printf(" Rownanie nie ma rozwiazania.\n");
    else {
      printf(" Rownanie ma dwa rozwiazania:\n");
      printf("x1 = %.2f, x2 = %.2f\n",
             (-b-sqrt(delta))/(2*a), (-b+sqrt(delta))/(2*a));
    }
  }

  return 0;
}
