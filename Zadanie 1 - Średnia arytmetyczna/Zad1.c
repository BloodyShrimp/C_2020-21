#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double average(int N, double suma);
double deviation(int N, double suma, double sumaK);

int main()
{
    int n = 0;
    double liczba = 0;
    double sum = 0;
    double sumSqr = 0;

    printf("Wprowadz dowolna ilosc liczb.\n");

    while(scanf("%lf", &liczba) != EOF)
    {
        sum += liczba;
        sumSqr += pow(liczba, 2);
        n++;
    }

    printf("Srednia wynosi: %f\n", average(n, sum));
    printf("Odchylenie standardowe wynosi: %f\n", deviation(n, sum, sumSqr));
    printf("Ilosc wpisanych liczb: %i\n", n);

    return 0;
}

double average(int N, double suma)
{
    return suma / N;
}

double deviation(int N, double suma, double sumaK)
{
    return sqrt((N * sumaK) - pow(suma, 2)) / N;
}
