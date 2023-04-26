#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double polan()
{
    char a[11];
    double f1,f2;
    scanf("%s",a);
    switch(a[0]){
        case '+':f1=polan();f2=polan();return f1+f2;
        case '-':f1=polan();f2=polan();return f1-f2;
        case '*':f1=polan();f2=polan();return f1*f2;
        case '/':f1=polan();f2=polan();return f1/f2;
        default:return atof(a);}
}
int main()
{
   int T;
   scanf("%d",&T);
   //getchar();
   int i;
   for(i=0;i<T;i++)
   {
       double res=0;
       res=polan();
       printf("case #%d:\n",i);
       printf("%.6f\n",res);
   }
    return 0;
}

