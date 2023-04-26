#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double polish_expr()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0]){
        case'+':f1 = polish_expr();f2 = polish_expr();return f1+f2;
        case'-':f1 = polish_expr();f2 = polish_expr();return f1-f2;
        case'*':f1 = polish_expr();f2 = polish_expr();return f1*f2;
        case'/':f1 = polish_expr();f2 = polish_expr();return f1/f2;
        default:return atof(a);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        double res = polish_expr();
        printf("case #%d:\n",cnt);
        printf("%f",res);
        cnt++;
    }
}
