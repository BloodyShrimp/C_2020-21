#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define R_MAX 65535

unsigned int monte_carlo(int seed_x, int seed_y, unsigned int n) /* funkcja generująca losowe punkty x y i sprawdzajaca czy trafiaja w okrag */
{
    unsigned int i = 0, k = 0;
    int previous_x = seed_x;
    int previous_y = seed_y;
    int integral_x = 0, integral_y = 0;
    long double x = 0.0, y = 0.0, z = 0.0;
    for(i = 0; i < n; i++)
    {
        integral_x = (((75 * (previous_x + 1)) % (R_MAX + 2)) - 1);
        integral_y = (((75 * (previous_y + 1)) % (R_MAX + 2)) - 1);

        previous_x = integral_x;
        previous_y = integral_y;

        x = (integral_x * 1.0) / (R_MAX + 1.0);
        y = (integral_y * 1.0) / (R_MAX + 1.0);

        z = x*x + y*y;
        if(z < 1)
        {
            k++;
        }

    }

    return k; /* zwraca ilosc punktow ktore trafily w okrag */
}

int main()
{
    unsigned int n = 0, k = 0;
    int seed_x = 0, seed_y = 0;
    long double pi = 0.0;

    printf("Podaj liczbe n generowanych puntkow: ");
    scanf("%u", &n);
    printf("Podaj seed dla punktow x: ");
    scanf("%d", &seed_x);
    printf("Podaj seed dla punktow y: ");
    scanf("%d", &seed_y);

    k = monte_carlo(seed_x, seed_y, n);
    pi = 4.0 * ((k * 1.0) / n);

    printf("Liczba prob: %u\nPrzyblizona wartosc pi = %.10Lf\n", n, pi);

    return 0;
}