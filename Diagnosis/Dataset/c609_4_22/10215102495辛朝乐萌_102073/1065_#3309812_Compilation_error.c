#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define len 1000

double expr(char s[])
{
    double f1,f2;
    switch (s[0]) {
        case'+':{f1=expr();f2=expr();return f1+f2;}
        case'-':{f1=expr();f2=expr();return f1-f2;}
        case'*':{f1=expr();f2=expr();return f1*f2;}
        case'/':{f1=expr();f2=expr();return f1/f2;}
        default:return atof(s);
}

int main()
{
    int t;
    scanf("%d",&t);
    char s[10];
    for(int i=0;i<t;i++){
        scanf("%s",s);
        printf("case #%d:\n",i);
        double res=expr();
        printf("%lf\n",res);
    }
    expr;
    return 0;
}