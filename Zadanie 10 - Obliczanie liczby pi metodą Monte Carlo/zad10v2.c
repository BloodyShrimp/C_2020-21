#include <stdio.h>
#include <stdlib.h>
#define SEED 45291786

int main()
{
    long double x = 0.0, y = 0.0, z = 0.0, pi = 0.0;
    unsigned long int i = 0, k = 0, n = 0;

    printf("Podaj ilosc iteracji do obliczenia pi: ");
    scanf("%lu", &n);

    srand(SEED);
    for(i = 0; i < n; i++)
    {
        x = (long double)rand() / RAND_MAX;
        y = (long double)rand() / RAND_MAX;

        z = x*x + y*y;
        if(z < 1) k++;
    }

    pi = (long double)k / n * 4;


    printf("Liczba prob: %lu\nPrzyblizona wartosc pi = %.10Lf\n", n, pi);

    return 0;
}