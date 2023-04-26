#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
double polan(char(*a)[11])
    if(isdigit((*a)[0]))
        r
{eturn atof(*a);
    else
    {
        if((*a)[0] == '+')
            return polan(a+1) + polan(a+2);
        else if((*a)[0] == '-')
            return polan(a+2) - polan(a+1);
        else if((*a)[0] == '+')
            return polan(a+2)/polan(a+1);
        else if((*a)[0] == '*')
            return polan(a+2) * polan(a+1); 
    }
}
错误示例
*/
double polish_expr()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0])
    {
        case '+':f1 = polish_expr();f2 = polish_expr();return f1 + f2;
        case '-':f1 = polish_expr();f2 = polish_expr();return f1 - f2;
        case '*':f1 = polish_expr();f2 = polish_expr();return f1 * f2;
        case '/':f1 = polish_expr();f2 = polish_expr();return f1 / f2;
        default: return atof(a);
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        printf("case #%d:\n%.6lf\n",i,polish_expr());
        
    }
}