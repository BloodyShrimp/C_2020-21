#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long double A, B, C; /* zmienne wspolczynnikow rownania */
    long double delta; /* zmienna delty */
    long double wynik1, wynik2; /* zmienne wynikow rownania */

    printf("Podaj wspolczynnik przy x^2 (nie moze on wynosic 0): ");
    while(scanf("%Lf", &A)) /* uzytkownik podaje wspolczynnik A */
    {
        if(A == 0) /*jezeli uzytkownik podal 0 program informuje o blednym wejsciu i prosi o ponowne podanie wspolczynnika */
        {
            printf("Wspolczynnik nie moze wynosic 0! Podaj inny wspolczynnik: ");
        }
        else
        {
            break;
        }
    }

    printf("Podaj wspolczynnik przy x^1: ");
    scanf("%Lf", &B); /* uzytkownik podaje wspolczynnik B */

    printf("Podaj wspolczynnik przy x^0: ");
    scanf("%Lf", &C); /* uzytkownik podaje wspolczynnik C */

    delta = (B*B) - (4*A*C); /* obliczenie delty */

    if(delta < 0) /* sprawdzenie mozliwych przypadkow delty i podanie odpowiedniego wyniku */
    {
        printf("Rownanie nie ma rozwiazan rzeczywistych.\n");
    }
    else if(delta == 0)
    {
        wynik1 = -(B / (2*A));
        printf("Rownanie ma jedno rozwiazanie rzeczywiste:\nx1 = %Lf\n", wynik1);
    }
    else if(delta > 0)
    {
        wynik1 = (-B - sqrt(delta)) / (2*A);
        wynik2 = (-B + sqrt(delta)) / (2*A);
        printf("Rownanie ma dwa rozwiazania rzeczywiste:\nx1 = %Lf\nx2 = %Lf\n", wynik1, wynik2);
    }

    return 0;
}
