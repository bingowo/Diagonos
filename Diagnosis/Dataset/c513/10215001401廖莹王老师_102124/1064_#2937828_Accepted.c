#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
double jisuan()
{
    char s[10]={0};
    scanf("%s",s);
    double f1=0,f2=0;
    if(s[1]) return atof(s);
   else
 
     switch(s[0])
    {
        case '+':f1=jisuan();f2=jisuan();return f1+f2;
        case '-':f1=jisuan();f2=jisuan();return f1-f2;
        case '*':f1=jisuan();f2=jisuan();return f1*f2;
        case '/':f1=jisuan();f2=jisuan();return f1/f2;
        default:return atof(s);
    }
 
}
int main()
{
    int n,h;
    scanf("%d",&n);
    for(h=0;h<n;h++)
    {
        double result=0;
        printf("case #%d:\n",h);
        result=jisuan();
        printf("%.6lf\n",result);

    }

}
