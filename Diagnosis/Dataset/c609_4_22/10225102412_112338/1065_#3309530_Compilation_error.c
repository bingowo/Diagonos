#include <stdio.h>
#include <stdlib.h>
#define N 10

double eval()
{
    char s[N+1];
    if (strchr("+-*/",(scanf("%s",*s)))){
        double opd1=eval(),opd2=eval();
        switch (*s){
            case "+": return opad1+opd2;
            case "-": return opad1-opd2;
            case "*": return opad1*opd2;
            case "/": return opad1/opd2;
        }
    }
    return atof(s);
}

int main()
{
    int I,T,n;
    for (scanf("%d",&T),I=0;I<T;I++) printf("case #%d:\n""%f\n",I,eval());
    return 0;
}