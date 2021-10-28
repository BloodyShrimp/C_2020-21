#include <stdio.h>
#include <stdlib.h>

long double newton_iteracyjnie(int n, int k); /* deklaracje funkcji */
long double newton_rekurencyjnie(int n, int k);

int main(int narg, char *Arg[]) /* pierwszy argument to sposób liczenia (1 - iteracyjnie 2 - rekurencyjnie) drugi to n trzeci to k */
{
    int n, k;

    sscanf(Arg[2], "%d", &n); /* zamiana stringa na int */
    sscanf(Arg[3], "%d", &k);

    if(k > n || k < 0 || n < 0) /* warunek poprawności n i k */
    {
        printf("k i n musza byc naturalne i spelniac warunek:\n0 <= k <= n\n");
        
    }
    else if (*Arg[1] == '1') /* obliczenie iteracyjnie */
    {
        printf("Iteracyjnie\nSymbol newtona z n = %d k = %d wynosi: %Lf\n", n, k, newton_iteracyjnie(n, k));
    }
    else if(*Arg[1] == '2') /* obliczenie rekurencyjnie */
    {
        printf("Rekurencyjnie\nSymbol newtona z n = %d k = %d wynosi: %Lf\n", n, k, newton_rekurencyjnie(n, k));
    }
    return 0;
}

long double newton_iteracyjnie(int n, int k)
{
    int i, j;
    long double wynik;

    long double **pascal = (long double **)malloc((n+1) * sizeof(long double *)); /* alokacja pamięci tablicy */
    for(i = 0; i < n+1; i++)
    {
        pascal[i] = (long double *)malloc((i+1) * sizeof(long double));
    }
    
    for(i = 0; i <= n; i++) /* ustawienie przypadków k = 0 i k = n na 1 */
    {
        pascal[i][0] = 1;

        for(j = 0; j <= k; j++)
        {
            if(i == j)
            {
                pascal[i][j] = 1;
            }
        }
        
    }

    for(j = 1; j <= k; j++) /* wypełnienie trójkątu pascala */
    {
        for(i = j + 1; i <= n; i++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
        
    }

    
    wynik = pascal[n][k];

    for(i = 0; i < n+1; i++) /* zwolnienie pamięci */
    {
        free(pascal[i]);
    }
    free(pascal);

    return wynik;
}

long double newton_rekurencyjnie(int n, int k)
{
    if(k == 0 || k == n) /* obliczenie symbolu newtona rekurencyjnie */
    {
        return 1;
    }
    else
    {
        return newton_rekurencyjnie(n - 1, k - 1) + newton_rekurencyjnie(n - 1, k);
    }
    
    
}