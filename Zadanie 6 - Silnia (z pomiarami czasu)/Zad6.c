#include <stdio.h>
#include <stdlib.h>

long double silnia_rekurencyjnie(int n) /* obliczenie silni rekurencyjnie */
{
    if (n < 2)
    {
        return 1;
    }

    return n*silnia_rekurencyjnie(n-1);

}

long double silnia_iteracyjnie(int n) /* obliczenie silni iteracyjnie */
{
    long double silnia = 1;
    int i;

    for (i = n; i > 1; i--)
    {
        silnia *= i;
    }

    return silnia;
}

int main(int narg, char *Arg[]) /* pierwszy argument to sposób liczenia 1 - rekurencyjnie 2 - iteracyjnie drugi argument to liczba n */
{
    int n, i; /* n - silnia liczby do policzenia s - informacja o sposobie obliczenia i - zmienna petli */

    long double factorialRekurencyjnie; /* zmienna przechowujaca wynik rekurencyjny */
    long double factorialIteracyjnie; /* zmienna przechowujaca wynik iteracyjny */

    sscanf(Arg[2], "%d", &n); /* zamiana stringa na int */

    if (*Arg[1] == '1')
    {
        for (i = 0; i < 10000000; i++) /* zapetlam obliczenie silni 10 milionow razy dla dokladniejszego sprawdzenia czasu obliczen */
        {
            factorialRekurencyjnie = silnia_rekurencyjnie(n);
        }
        printf("%d! rekurencyjnie = %Lf", n, factorialRekurencyjnie);
    }
    else if (*Arg[1] == '2')
    {
        for (i = 0; i < 10000000; i++) /* zapetlam obliczenie silni 10 milionow razy dla dokladniejszego sprawdzenia czasu obliczen */
        {
            factorialIteracyjnie = silnia_iteracyjnie(n);
        }
        printf("%d! iteracyjnie = %Lf", n, factorialIteracyjnie);
    }

    return 0;
}
