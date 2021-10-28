#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void na_rzymskie(int n);
void na_arabskie(char *n);

int main()
{
    char liczba[32] = "";
    int arabska = 0;
    printf("Podaj liczbe arabska lub rzymska: "); /* wprowadzenie liczby */
    scanf("%s", &liczba);
    if(isdigit(liczba[0])) /* jesli liczba jest arabska kowertuje na rzymska */
    {
        arabska = atoi(liczba); /* zamiana stringa na int */
        na_rzymskie(arabska);
    }
    else if(isalpha(liczba[0])) /* jesli liczba jest rzymska konwertuje na arabska */
    {
        na_arabskie(liczba);
    }


    return 0;
}

struct RZYM
    {
    int arab;
    char *rzym;
    } 
    rz[] =
        {
            {1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"}, {40,"XL"},{50,"L"},{90,"XC"},{100,"C"}, {400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}
        },
    mrz[] =
        {
            {1, "I"},{5, "V"},{10, "X"},{50, "L"},{100, "C"},{500, "D"},{1000, "M"}
        };


void na_rzymskie(int n)
{
    char liczbaRzymska[32] = "";
    int liczbaArabska = n;
    int i = 0;

    while (n > 0)
    {
        for(i = 12; i >= 0; i--) /* zamiana od najwiekszych liczb rzymskich to najmniejszych */
        {
            if(n >= rz[i].arab)
            {
                strcat(liczbaRzymska, rz[i].rzym); /* dodanie do stringa znaku cyfry rzymskiej */
                n -= rz[i].arab; /* zmniejszenie liczby o dodaną cyfre rzymska */
                break;
            }
        }
    }
    printf("%d = %s\n", liczbaArabska, liczbaRzymska);
}

void na_arabskie(char *n)
{
    int length = strlen(n) - 1;
    int i = 0;
    int current = 0;
    int wynik = 0;
    int previous = 0;

    for(length; length >= 0; length--) /* sprawdzanie znakow liczby rzymskiej od prawej */
    {
        for(i = 6; i >= 0; i--) /* znalezienie cyfry w tablicy struktur */
        {
            if(n[length] == *mrz[i].rzym)
            {
                current = mrz[i].arab;
            }
        }
        if(current >= previous) /* sprawdzenie czy aktualnie sprawdzana cyfra jest mniejsza lub wieksza od poprzedniej */
        {
            previous = current;
            wynik += current; /* jezeli wieksza dodaje do wyniku */
        }
        else
        {
            wynik -= current; /* jezeli mniejsza odejmuje od wyniku */
        }
    }
    printf("%s = %d\n", n, wynik);
}