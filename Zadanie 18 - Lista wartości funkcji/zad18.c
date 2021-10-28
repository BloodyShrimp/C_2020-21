#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define stos_rozmiar 200
#define MAX 200

double stos[stos_rozmiar] = {0.0};
int amount = 0;
double x = 0.0;
double y = 0.0;

void push(double x)
{
    if (amount >= stos_rozmiar - 1)
    {
        printf("Maksymalny rozmiar stosu zostal przekroczony.\n");
        exit(0);
    }
    else
    {
        amount++;
        stos[amount] = x;
    }
}

double pop()
{
    double x = 0;
    if (amount <= 0)
    {
        printf("Stos jest pusty.\n");
        exit(0);
    }
    else
    {
        x = stos[amount];
        stos[amount] = 0.0;
        amount--;
        return x;
    }
}

void addition()
{
    x = pop();
    y = pop();
    push(y + x);
}

void subtraction()
{
    x = pop();
    y = pop();
    push(y - x);
}

void multiplication()
{
    x = pop();
    y = pop();
    push(y * x);
}

void division()
{
    x = pop();
    y = pop();
    push(y / x);
}

void power()
{
    x = pop();
    y = pop();
    push(pow(y, x));
}

void natural_logarithm()
{
    x = pop();
    push(log(x));
}

void logarithm()
{
    x = pop();
    y = pop();
    push((log(x)) / (log(y)));
}

void sine()
{
    x = pop();
    push(sin(x));
}

void cosine()
{
    x = pop();
    push(cos(x));
}

void tangent()
{
    x = pop();
    push(tan(x));
}

int main()
{
    int n = 0;
    int i = 0;
    char temp[20] = "";
    char *ptr;
    char *funkcja[MAX];
    double x_start = 0.0;
    double x_end = 0.0;
    double x_delta = 0.0;

    printf("Wprowadz wartosc poczatkowa x: ");
    scanf("%lf", &x_start);
    printf("Wprowadz wartosc koncowa x: ");
    scanf("%lf", &x_end);
    printf("Wprowadz krok delta x: ");
    scanf("%lf", &x_delta);

    printf("Wprowadz rownanie w odwrotnej notacji polskiej.\nObslugiwane operatory jednoargumentowe to: ln sin cos tan\nObslugiwane operatory dwuargumentowe to: + - * / ^ log\n");
    printf("Na koncu rownania nalezy umiescic znak \"=\"\n");

    while(scanf("%s", temp))
    {  
        funkcja[n] = malloc(20*sizeof(char));
        strcpy(funkcja[n], temp);
        n++;
        if(!strcmp(temp, "="))
        {
            break;
        }
    }
    for(; fabs(x_start) <= fabs(x_end); x_start += x_delta)
    {
        for(i = 0; i < n; i++)
        {
            if (!strcmp(funkcja[i], "+"))
            {
                addition();
            }
            else if (!strcmp(funkcja[i], "-"))
            {
                subtraction();
            }
            else if (!strcmp(funkcja[i], "*"))
            {
                multiplication();
            }
            else if (!strcmp(funkcja[i], "/"))
            {
                division();
            }
            else if (!strcmp(funkcja[i], "^"))
            {
                power();
            }
            else if (!strcmp(funkcja[i], "="))
            {
                x = pop();
                printf("f(%.10g) = %.10g\n", x_start, x);
                break;
            }
            else if (!strcmp(funkcja[i], "ln"))
            {
                natural_logarithm();
            }
            else if (!strcmp(funkcja[i], "log"))
            {
                logarithm();
            }
            else if (!strcmp(funkcja[i], "sin"))
            {
                sine();
            }
            else if (!strcmp(funkcja[i], "cos"))
            {
                cosine();
            }
            else if (!strcmp(funkcja[i], "tan"))
            {
                tangent();
            }
            else if (!strcmp(funkcja[i], "x"))
            {
                push(x_start);
            }
            else
            {
                x = strtod(funkcja[i], &ptr);
                push(x);
            }
        }
        if (x_delta == 0)
        {
            break;
        }
    }
    return 0;
}