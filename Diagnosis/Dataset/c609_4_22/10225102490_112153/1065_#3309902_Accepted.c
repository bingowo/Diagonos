#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

double eval()
{

    char s[N+1];
    scanf("%s",s);
    if (strchr("+-*/",*s))
    {
        double opd1 = eval(), opd2 = eval();
        switch(*s)
        {
            case '+' : return opd1 + opd2;
            case '-' : return opd1 - opd2;
            case '*' : return opd1 * opd2;
            case '/' : return opd1 / opd2;
        }
    }
    return atof(s);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int I = 0; I < T; I++)
    {
        printf("case #%d:\n",I);
        printf("%f\n",eval());
    }
    return 0;
}
