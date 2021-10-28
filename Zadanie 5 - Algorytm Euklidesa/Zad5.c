#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m, n;
    int c;

    printf("Wprowadz dwie liczby oddzielone spacja dla ktorych chcesz policzyc NWD.\n");
    scanf("%d %d", &m, &n);

    int a = m;
    int b = n;

    while(n != 0)
    {
        c = m%n;
        m = n;
        n = c;
    }

    printf("NWD(%d, %d) = %d\n", a, b, m);

    return 0;
}
