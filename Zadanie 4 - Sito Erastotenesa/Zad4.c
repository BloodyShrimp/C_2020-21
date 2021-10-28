#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int a;

    printf("Podaj liczbe naturalna n dla ktorej chcesz znalezc wszystkie liczby pierwsze z przedzialu [2,n]\n");
    scanf("%d", &a);

    int N = a + 1;

    bool A[N];
    A[0] = false; /* ustawia indeks 0 i 1 na false */
    A[1] = false;

    int i,j; /* liczniki petli */

    for(i = 2; i < N; i++) /* ustawia cala tablice oprocz 0 i 1 na true */
    {
        A[i] = true;
    }

    for(i = 2; i*i <= N; i++) /* sito */
    {
        if(A[i] == true) /* sprawdza czy liczba jest pierwsza */
        {
            for(j = i*i; j <= N; j += i) /* wykresla wszystkie wielokrotnosci znalezionej liczby */
            {
                A[j] = false;
            }
        }
    }

    for(i = 2; i < N; i++) /* wypisuje indeksy ktore sa liczbami pierwszymi */
    {
        if(A[i] == true)
        {
            printf("%d, ", i);
        }
    }

    return 0;
}
