#include <stdio.h>

int A()
{
    char c1,c2;
    int v = 0;
    if ((c1=getchar()) == '(')
    {
        if ((c2=getchar()) == '(')
        {
            ungetc(c2,stdin);
            v = 2 * A();
        }
        else v++;
        if (c1 != '\n') v += A();
    }
    return v;
}

int main()
{
    printf("%d",A());
}