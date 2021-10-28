#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define n 200

double stos[n] = {0.0};
int amount = 0;
double x = 0.0;
double y = 0.0;

void push(double x)
{
    if(amount >= n-1)
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
    if(amount <= 0)
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
    push(y+x);
}

void subtraction()
{
    x = pop();
    y = pop();
    push(y-x);
}

void multiplication()
{
    x = pop();
    y = pop();
    push(y*x);
}

void division()
{
    x = pop();
    y = pop();
    push(y/x);
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
    push((log(x))/(log(y)));
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
    char oper[10] = "";
    char *ptr;

    printf("Wprowadz rownanie w odwrotnej notacji polskiej.\nObslugiwane operatory jednoargumentowe to: ln sin cos tan\nObslugiwane operatory dwuargumentowe to: + - * / ^ log\n");
    printf("Na koncu rownania nalezy umiescic znak \"=\"\nAby zakonczyc dzialanie kalkulatora nalezy wpisac znak \"q\"\n");
    while(scanf("%s", oper))
    {
        if(!strcmp(oper, "q"))
        {
            break;
        }
        else if(!strcmp(oper,"+"))
        {
            addition();
        }
        else if(!strcmp(oper,"-"))
        {
            subtraction();
        }
        else if(!strcmp(oper,"*"))
        {
            multiplication();
        }
        else if(!strcmp(oper,"/"))
        {
            division();
        }
        else if(!strcmp(oper, "^"))
        {
            power();
        }
        else if(!strcmp(oper, "="))
        {
            x = pop();
            printf("%g\n", x);
        }
        else if(!strcmp(oper, "ln"))
        {
            natural_logarithm();
        }
        else if(!strcmp(oper, "log"))
        {
            logarithm();
        }
        else if(!strcmp(oper, "sin"))
        {
            sine();
        }
        else if(!strcmp(oper, "cos"))
        {
            cosine();
        }
        else if(!strcmp(oper, "tan"))
        {
            tangent();
        }
        else
        {
            x = strtod(oper, &ptr);
            push(x);
        }
    }

    return 0;
}