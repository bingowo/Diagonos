#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double polish_expr(char a[11])
{
    double f1,f2;
    switch(a[0]){
        case'+':f1 = polish_expr(a);f2 = polish_expr(a);return f1+f2;
        case'-':f1 = polish_expr(a);f2 = polish_expr(a);return f1-f2;
        case'*':f1 = polish_expr(a);f2 = polish_expr(a);return f1*f2;
        case'/':f1 = polish_expr(a);f2 = polish_expr(a);return f1/f2;
        default:return atof(a);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        char s;
        gets(s);
        double res = polish_expr(s);
        printf("case #%d:\n",cnt);
        printf("%f",res);
        cnt++;
    }
}
