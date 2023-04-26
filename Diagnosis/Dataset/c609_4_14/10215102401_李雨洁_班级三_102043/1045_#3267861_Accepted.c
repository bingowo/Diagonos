#include<stdio.h>
void A()//除去块注释
{
    char c = getchar(); if (c == EOF) return;
    char d = getchar(); if (d == EOF) return;
    while (c != '*' || d != '/')
    {
        c = d;
        d = getchar();
        if (d == EOF) return;
    }
}
void B()//除去行注释
{
    char c, d;
    while (c != '\n')
    {
        c = getchar();
        if (c == EOF) return;
    }
    putchar(c);
}
void C(char c)
{
    putchar(c);
    char d;
    while ((d = getchar()) != c)
    {
        if (d == EOF) return;
        putchar(d);
        if (d == '\\') putchar(getchar());
    }
    putchar(d);
}
int main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        char d;
        if (c == '/')
        {
            if ((d = getchar()) == '*')
            {
                if (d == EOF) return;
                A();
            }
            else if (d == '/')  B();
            else
            {
                putchar(c);putchar(d);
            }
        }
        else if (c == '\'' || c == '"')   C(c);
        else   putchar(c);
    }
    return 0;
}