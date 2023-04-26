#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double fuc();

int main()
{
    int T = 0;
    scanf("%d", &T);
    for(int k = 0; k < T; k++)
    {
        double answer = fuc();
        printf("case #%d:\n", k);
        printf("%.6lf", answer);
    }

    return 0;
}

double fuc()
{
    char a[11];
    double f1, f2;
    scanf("%s", a);
    switch(a[0])
    {
    case'+':
        f1 = fuc(), f2 = fuc();
        return f1 + f2;
    case'-':
        f1 = fuc(), f2 = fuc();
        return f1 - f2;
    case'*':
        f1 = fuc(), f2 = fuc();
        return f1 * f2;
    case'/':
        f1 = fuc(), f2 = fuc();
        return f1 / f2;
    default:
        return atof(a);
    }
}
