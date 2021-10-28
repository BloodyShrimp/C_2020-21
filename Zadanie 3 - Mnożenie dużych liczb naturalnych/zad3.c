#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int number1[1000];
    int number2[1000];
    int product[2000] = {0};
    char s1[1001];
    char s2[1001];
    printf("Podaj pierwsza liczbe naturalna: ");
    scanf("%s", s1);
    printf("Podaj druga liczbe naturalna: ");
    scanf("%s", s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i, j, tmp;
    
    for(i = l1 - 1, j = 0; i >= 0; i--, j++)
    {
        number1[j] = s1[i] - '0';
    }
    for(i = l2 - 1, j = 0; i >= 0; i--, j++)
    {
        number2[j] = s2[i] - '0';
    }
    for(i = 0; i < l2; i++)
    {
        for(j = 0; j < l1; j++)
        {
            product[i+j] += number2[i] * number1[j];
        }
    }
    for(i = 0; i < l1 + l2; i++)
    {
        tmp = product[i]/10;
        product[i] = product[i] % 10;
        product[i + 1] = product[i + 1] + tmp;
    }
    for(i = l1 + l2; i >= 0; i--)
    {
        if(product[i] > 0)
        {
            break;
        }
    }
    printf("Wynik mnozenia: ");
    for(i = l1 + l2; i >= 0; i--)
    {
        printf("%d", product[i]);
    }
    printf("\n");

    return 0;
}