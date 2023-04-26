#include <stdio.h>
#include <stdlib.h>
double polish_expr(){
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0]){
        case'+':f1=polish_expr();f2=polish_expr();return f1+f2;
        case'-':f1=polish_expr();f2=polish_expr();return f1-f2;
        case'*':f1=polish_expr();f2=polish_expr();return f1*f2;
        case'/':f1=polish_expr();f2=polish_expr();return f1/f2;
        default:return atof(a);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
       printf("case #%d:\n",i);
        printf("%.6f\n",polish_expr());
    }

}