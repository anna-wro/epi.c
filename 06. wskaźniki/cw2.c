#include <stdio.h>
#include <math.h> //kompilować z -lm

int kwadratowe(double a, double b, double c, double *x1, double *x2)
{
	if(a == 0.0) return -1; //to nie jest równanie kwadratowe
	
	double delta = b*b-4.0*a*c;
	
	if(delta < 0.0) return 0; //parabola nie przecina osi X
	
	if(delta == 0.0)
	{
		*x1 = -b / (2.0*a);
		return 1; //parabola dotyka oś X w jednym punkcie
	}
	
	double pdelta = sqrt(delta);
	
	*x1 = (-b - pdelta)/(2.0*a);
	*x2 = (-b + pdelta)/(2.0*a);
	
	return 2; //parabola przecina oś X w dwóch punktach
}

int main()
{
	double a,b,c;
	printf("Podaj a = ");
	scanf("%lf",&a);
	printf("b = ");
	scanf("%lf",&b);
	printf("c = ");
	scanf("%lf",&c);




	return 0;
}