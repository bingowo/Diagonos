#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double polish_expr(){
char a[11];
double f1,f2;
scanf("%s",a);
switch(a[0]){
case '+':f1 = polish_expr();f2 = polish_expr();return f1 + f2;
case '-':f1 = polish_expr();f2 = polish_expr();return f1 - f2;
case '*':f1 = polish_expr();f2 = polish_expr();return f1 * f2;
case '/':f1 = polish_expr();f2 = polish_expr();return f1/f2;
default:return atof(a);
}
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        double res =  polish_expr();
        printf("case #%d:\n%f\n",i,res);

    }
    return 0;
}
