#include <stdio.h>

char bin[32];

int to_binary_modulus(unsigned int n) /* fukncja zamieniajaca liczbe dziesietna na binarna przy uzyciu mod 2 */
{
    int bits;
    for (bits = 0; n > 0; bits++)
    {
        bin[bits] = n % 2;
        n = n / 2;
    }
    return bits;
}

int to_binary_bit_shift(unsigned int n) /* fukncja zamieniajaca liczbe dziesietna na binarna przy uzyciu operacji bitowych */
{
    int i = 31;
    int flag = 0;
    int bits = 0;
    while (i--)
    {
        if (n >> i & 1 & !flag)
        {
            flag = 1;
        }
        if (flag)
        {
            bin[i] = (n >> i) & 1;
            bits++;
        }
    }
    return bits;
}

int main()
{
    int i, v;
    unsigned int n;

    printf("Wprowadz sposob obliczen 1 - modulo 2 - operacje bitowe: ");
    scanf("%d", &v);

    printf("Wprowadź liczbę do przekonwertowania: ");
    scanf("%d", &n);

    if(v == 1)
    {
        i = to_binary_modulus(n);
    }
    else if(v == 2)
    {
        i = to_binary_bit_shift(n);
    }
    printf("Ta liczba w postaci binarnej to: ");
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}