#include <stdio.h>
#include <stdlib.h>

double poblish_expr();

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%lf\n",poblish_expr());
    }
    return 0;
}

double poblish_expr()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0]){
        case'+':f1=poblish_expr();f2=poblish_expr();return f1+f2;
        case'-':f1=poblish_expr();f2=poblish_expr();return f1-f2;
        case'*':f1=poblish_expr();f2=poblish_expr();return f1*f2;
        case'/':f1=poblish_expr();f2=poblish_expr();return f1/f2;
        default:return atof(a);
    }
}
