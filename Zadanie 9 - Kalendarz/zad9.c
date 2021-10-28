#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char * WEEKS[];
int dow(int y, int m, int d);

int main()
{
    int y, m, d, v, j;
    printf("Podaj uzywany kalendarz 1 - gregorianski 2 - julianski: ");
    scanf("%d", &v);
    printf("Podaj date w formacie dd mm yyyy: ");
    scanf("%d %d %d", &d, &m, &y);

    if(v == 1) /* sprawdzenie rodzaju podanego kalendarza */
    {
        printf("Dzien tygodnia to %s\n", WEEKS[dow(y, m, d)]);
    }
    else if(v == 2)
    {
        j = ((y/100) * (0.75)) - 1.25; /* obliczenie liczby dni o ktore nalezy przesunac date w kalendarzu julianskim aby otrzymac ja w gregorianskim */
        printf("Dzien tygodnia to %s\n", WEEKS[dow(y, m, (d+j))]);
    }

    char cmd[64];
    sprintf(cmd, "cal %d %d", m, y);
    system(cmd);

    return 0;
}

int dow(int y, int m, int d) /* obliczenie dnia tygodnia */
{
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

const char * WEEKS[] = {"Niedziela", "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota"};